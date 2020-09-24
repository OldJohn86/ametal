/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ADC ���̣�ͨ����׼�ӿ�ʵ��
 *
 * - �������裺
 *   1. PIOA_0 (ADC ͨ�� 0) ����ģ�����롣
 *
 * - ʵ������
 *   1. ���������ѹ����ֵ��
 *
 * \note
 *    1. ʹ�� ADC ģ�鹦�ܣ����뱣֤ ADC ģ���ϵ磻
 *    2. ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOA_9�������� PC���ڵ�RXD��
 *       PIOA_10�������� PC���ڵ�TXD��
 *
 * \par Դ����
 * \snippet demo_hk32f103rbt6_std_adc.c src_std_adc
 *
 * \internal
 * \par Modification History
 * - 1.00 17-08-29  fra, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_hk32f103rbt6_std_adc
 * \copydoc demo_hk32f103rbt6_std_adc.c
 */

/** [src_std_adc] */
#include "ametal.h"
#include "am_board.h"
#include "am_vdebug.h"
#include "am_delay.h"
#include "am_hk32f103rbt6_inst_init.h"
#include "demo_std_entries.h"
#include "demo_hk32f103rbt6_core_entries.h"

/**
 * \brief �������
 */
void demo_hk32f103rbt6_core_std_adc_entry (void)
{
    AM_DBG_INFO("demo hk32f103rbt6_core std adc int!\r\n");

    demo_std_adc_entry(am_hk32f103rbt6_adc1_inst_init(), 0);

}
/** [src_std_adc] */

/* end of file */