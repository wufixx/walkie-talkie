/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    mtk_auxadc.c
 *
 * Project:
 * --------
 *   Android_Software
 *
 * Description:
 * ------------
 *   This Module defines functions of mt6580 AUXADC
 *
 * Author:
 * -------
 * Toy Chen
 *
 ****************************************************************************/
#include "platform.h"
#include "mtk_auxadc_sw.h"
#include "mtk_auxadc_hw.h"

#ifdef CFG_AUXADC_SUPPORT
///////////////////////////////////////////////////////////////////////////////////////////
//// Define
static int adc_auto_set =0;
static int adc_rtp_set =1;
static unsigned short mt_tpd_read_adc(unsigned short pos) {
   *(volatile unsigned short *)AUXADC_TP_ADDR = pos;
   *(volatile unsigned short *)AUXADC_TP_CON0 = 0x01;
   while(0x01 & *(volatile unsigned short *)AUXADC_TP_CON0) { ; } //wait for write finish
   return *(volatile unsigned short *)AUXADC_TP_DATA0; 
}


#define CLK_GATING_CTRL1 (TOPCKGEN_BASE + 0x24)
#define SET_CLK_GATING_CTRL1 (TOPCKGEN_BASE + 0x54)
#define CLR_CLK_GATING_CTRL1 (TOPCKGEN_BASE + 0x84)

#define MT_CG_ADC_SW_CG          30

#define ADC_SET_BITS(REG, BS)       ((*(volatile u32*)(REG)) |= (u32)(BS))
#define ADC_CLR_BITS(REG, BS)       ((*(volatile u32*)(REG)) &= ~((u32)(BS)))
void mt_ADC_power_on()
{
	ADC_SET_BITS(CLR_CLK_GATING_CTRL1, (1<<MT_CG_ADC_SW_CG));

	mdelay(100);
}

void mt_ADC_power_off ()
{
	ADC_SET_BITS(SET_CLK_GATING_CTRL1, (1<<(MT_CG_ADC_SW_CG)));  //disable clock 

}

static void mt_auxadc_disable_penirq(void)
{	
	//disable RTP
	if(adc_rtp_set)
	{
		adc_rtp_set = 0;
		*(volatile unsigned short *)AUXADC_CON_RTP = 1;
	}		
	//Turn off PENIRQ detection circuit
	*(volatile unsigned short *)AUXADC_TP_CMD = 1;
	//run once touch function
	mt_tpd_read_adc(TP_CMD_ADDR_X);
}

//step1 check con3 if auxadc is busy
//step2 clear bit
//step3  read channle and make sure old ready bit ==0
//step4 set bit  to trigger sample
//step5  read channle and make sure  ready bit ==1
//step6 read data

///////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
//// Common API

int IMM_GetOneChannelValue(int dwChannel, int data[4], int* rawdata)
{
   unsigned int channel[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   int idle_count =0;
   int data_ready_count=0;
   
  // mutex_lock(&mutex_get_cali_value);
   /* in uboot no pms api
    if(enable_clock(MT65XX_PDN_PERI_AUXADC,"AUXADC"))
   {
	    //printf("hwEnableClock AUXADC !!!.");
	    if(enable_clock(MT65XX_PDN_PERI_AUXADC,"AUXADC"))
	    {printf("hwEnableClock AUXADC failed.");}
        
   }
	*/
   mt_ADC_power_on();
   
   if(dwChannel == PAD_AUX_XP)mt_auxadc_disable_penirq();	
   //step1 check con3 if auxadc is busy
   while ((*(volatile unsigned short *)AUXADC_CON2) & 0x01) 
   {
       printf("[adc_api]: wait for module idle\n");
       udelay(10000);
	   idle_count++;
	   if(idle_count>30)
	   {
	      //wait for idle time out
	      printf("[adc_api]: wait for aux/adc idle time out\n");
	      return -1;
	   }
   } 
   // step2 clear bit
   if(0 == adc_auto_set)
   {
	   //clear bit
	   *(volatile unsigned short *)AUXADC_CON1 = *(volatile unsigned short *)AUXADC_CON1 & (~(1 << dwChannel));
   }
   

   //step3  read channle and make sure old ready bit ==0
   while ((*(volatile unsigned short *)(AUXADC_DAT0 + dwChannel * 0x04)) & (1<<12)) 
   {
       printf("[adc_api]: wait for channel[%d] ready bit clear\n",dwChannel);
       udelay(10000);
	   data_ready_count++;
	   if(data_ready_count>30)
	   {
	      //wait for idle time out
	      printf("[adc_api]: wait for channel[%d] ready bit clear time out\n",dwChannel);
	      return -2;
	   }
   }
  
   //step4 set bit  to trigger sample
   if(0==adc_auto_set)
   {  
	  *(volatile unsigned short *)AUXADC_CON1 = *(volatile unsigned short *)AUXADC_CON1 | (1 << dwChannel);
   }
   //step5  read channle and make sure  ready bit ==1
   udelay(25);//we must dealay here for hw sample channel data
   while (0==((*(volatile unsigned short *)(AUXADC_DAT0 + dwChannel * 0x04)) & (1<<12))) 
   {
       printf("[adc_api]: wait for channel[%d] ready bit ==1\n",dwChannel);
       udelay(10000);
	 data_ready_count++;
	 if(data_ready_count>30)
	 {
	      //wait for idle time out
	      printf("[adc_api]: wait for channel[%d] data ready time out\n",dwChannel);
	      return -3;
	 }
   }
   ////step6 read data
   
   channel[dwChannel] = (*(volatile unsigned short *)(AUXADC_DAT0 + dwChannel * 0x04)) & 0x0FFF;
   if(rawdata)
   {
      *rawdata = channel[dwChannel];
   }
   //printf("[adc_api: imm mode raw data => channel[%d] = %d\n",dwChannel, channel[dwChannel]);
   //printf("[adc_api]: imm mode => channel[%d] = %d.%d\n", dwChannel, (channel[dwChannel] * 250 / 4096 / 100), ((channel[dwChannel] * 250 / 4096) % 100));
   data[0] = (channel[dwChannel] * 150 / 4096 / 100);
   data[1] = ((channel[dwChannel] * 150 / 4096) % 100);

   /*

   if(disable_clock(MT65XX_PDN_PERI_AUXADC,"AUXADC"))
   {
        printf("hwEnableClock AUXADC failed.");
   }
    mutex_unlock(&mutex_get_cali_value);
   */
   mt_ADC_power_off();
   return 0;
   
}

///////////////////////////////////////////////////////////////////////////////////////////

#endif 