/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_emi.h
 *
 * Project:
 * --------
 *   Android
 *
 * Description:
 * ------------
 *   This Module defines the EMI (external memory interface) related setting.
 *
 * Author:
 * -------
 *  EMI auto generator V0.01
 *
 *   Memory Device database last modified on 2014/11/5
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * WARNING!!!  WARNING!!!   WARNING!!!  WARNING!!!  WARNING!!!  WARNING!!! 
 * This file is generated by EMI Auto-gen Tool.
 * Please do not modify the content directly!
 * It could be overwritten!
 *============================================================================
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__

#include "emi.h"

#define COMBO_LPDDR2 (1+0)
#define COMBO_LPDDR3 (2+0)
#define COMBO_PCDDR3 (0+0)
#define NUM_EMI_RECORD (3)

int num_of_emi_records = NUM_EMI_RECORD ;

EMI_SETTINGS emi_settings[] =
{
     
	//H9TQ17ABJTMCUR
	{
		0x0,		/* sub_version */
		0x0203,		/* TYPE */
		9,		/* EMMC ID/FW ID checking length */
		0,		/* FW length */
		{0x90,0x01,0x4A,0x48,0x41,0x47,0x32,0x65,0x05,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* FW_ID */
		0x0002A052,		/* EMI_CONA_VAL */
		0x00000000,		/* EMI_CONH_VAL */
		0x66CB4619,		/* DRAMC_ACTIM_VAL */
		0x11000000,		/* DRAMC_GDDR3CTL1_VAL */
		0x000484C3,		/* DRAMC_CONF1_VAL */
		0x000053B1,		/* DRAMC_DDR2CTL_VAL */
		0xBFC90401,		/* DRAMC_TEST2_3_VAL */
		0x00801760,		/* DRAMC_CONF2_VAL */
		0xD10B5642,		/* DRAMC_PD_CTRL_VAL */
		0x91001941,		/* DRAMC_ACTIM1_VAL*/
		0x17000000,		/* DRAMC_MISCTL0_VAL*/
		0x000030F7,		/* DRAMC_ACTIM05T_VAL*/
		0x00615641,		/* DRAM_CRKCFG_VAL*/
		0x2301110D,		/* DRAMC_TEST2_4_VAL*/
		{0x40000000,0x40000000,0,0},		/* DRAM RANK SIZE */
		{0,0,0,0,0,0,0,0,0,0},		/* reserved 10 */
		0x00630001,		/* LPDDR3_MODE_REG1 */
		0x001A0002,		/* LPDDR3_MODE_REG2 */
		0x00020003,		/* LPDDR3_MODE_REG3 */
		0x00000006,		/* LPDDR3_MODE_REG5 */
		0x00FF000A,		/* LPDDR3_MODE_REG10 */
		0x0000003F,		/* LPDDR3_MODE_REG63 */
	} ,
	//KMQ7X000SA-B315
	{
		0x0,		/* sub_version */
		0x0203,		/* TYPE */
		9,		/* EMMC ID/FW ID checking length */
		0,		/* FW length */
		{0x15,0x01,0x00,0x51,0x37,0x58,0x53,0x41,0x42,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* FW_ID */
		0x00025052,		/* EMI_CONA_VAL */
		0x00000000,		/* EMI_CONH_VAL */
		0x66CB4619,		/* DRAMC_ACTIM_VAL */
		0x11000000,		/* DRAMC_GDDR3CTL1_VAL */
		0x000484C3,		/* DRAMC_CONF1_VAL */
		0x000053B1,		/* DRAMC_DDR2CTL_VAL */
		0xBFC90401,		/* DRAMC_TEST2_3_VAL */
		0x00800F60,		/* DRAMC_CONF2_VAL */
		0xD10B3642,		/* DRAMC_PD_CTRL_VAL */
		0x91000D21,		/* DRAMC_ACTIM1_VAL*/
		0x17000000,		/* DRAMC_MISCTL0_VAL*/
		0x000030F7,		/* DRAMC_ACTIM05T_VAL*/
		0x00615641,		/* DRAM_CRKCFG_VAL*/
		0x2301110D,		/* DRAMC_TEST2_4_VAL*/
		{0x20000000,0x20000000,0,0},		/* DRAM RANK SIZE */
		{0,0,0,0,0,0,0,0,0,0},		/* reserved 10 */
		0x00630001,		/* LPDDR3_MODE_REG1 */
		0x001A0002,		/* LPDDR3_MODE_REG2 */
		0x00020003,		/* LPDDR3_MODE_REG3 */
		0x00000001,		/* LPDDR3_MODE_REG5 */
		0x00FF000A,		/* LPDDR3_MODE_REG10 */
		0x0000003F,		/* LPDDR3_MODE_REG63 */
	} ,
	//H9TP17ABLDMCNR
	{
		0x0,		/* sub_version */
		0x0202,		/* TYPE */
		9,		/* EMMC ID/FW ID checking length */
		0,		/* FW length */
		{0x90,0x01,0x4A,0x48,0x41,0x47,0x32,0x65,0x04,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* FW_ID */
		0x000250A2,		/* EMI_CONA_VAL */
		0x00000000,		/* EMI_CONH_VAL */
		0x44584493,		/* DRAMC_ACTIM_VAL */
		0x11000000,		/* DRAMC_GDDR3CTL1_VAL */
		0x00048483,		/* DRAMC_CONF1_VAL */
		0x000032B1,		/* DRAMC_DDR2CTL_VAL */
		0xBFC80401,		/* DRAMC_TEST2_3_VAL */
		0x00000040,		/* DRAMC_CONF2_VAL */
		0xC10B2342,		/* DRAMC_PD_CTRL_VAL */
		0x81000510,		/* DRAMC_ACTIM1_VAL*/
		0x07000000,		/* DRAMC_MISCTL0_VAL*/
		0x00002232,		/* DRAMC_ACTIM05T_VAL*/
		0x00613541,		/* DRAM_CRKCFG_VAL*/
		0x1701110D,		/* DRAMC_TEST2_4_VAL*/
		{0x40000000,0x40000000,0,0},		/* DRAM RANK SIZE */
		{0,0,0,0,0,0,0,0,0,0},		/* reserved 10 */
		0x00C30001,		/* LPDDR2_MODE_REG1 */
		0x00060002,		/* LPDDR2_MODE_REG2 */
		0x00020003,		/* LPDDR2_MODE_REG3 */
		0x00000006,		/* LPDDR2_MODE_REG5 */
		0x00FF000A,		/* LPDDR2_MODE_REG10 */
		0x0000003F,		/* LPDDR2_MODE_REG63 */
	} ,
};

#endif /* __CUSTOM_EMI__ */
