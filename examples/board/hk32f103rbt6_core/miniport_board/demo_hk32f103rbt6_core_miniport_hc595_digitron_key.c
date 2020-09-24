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
 * \brief MiniPort-View + MiniPort-595 + MiniPort-KEY ���̣�ͨ����׼�ӿ�ʵ��
 *
 * - ��������
 *   1. ��ȷ��am_hwconf_hk32f103rbt6_spi_int��c��spi2�豸��Ϣ�ṹ����cs_delay����ֵΪ0��
 *   2. �Ƚ� MiniPort-595 ����ֱ���� HK32F103RBT6 �� MiniPort �����ӣ�
 *   3. �� MiniPort-View ������ MiniPort-595 �ӿ������ӣ�
 *   4. �� MiniPort-KEY �� MiniPort-View ���ӡ�
 *
 * - ʵ������
 *   1. ����һ����������λ�������ʾ������ŵĶ����ƣ�
 *   2. ż�����ʱ���������˸���������ʱ������ܲ���˸��
 *
 * \note
 *    ���Ա� Demo ������ am_prj_config.h �ڽ� AM_CFG_KEY_GPIO_ENABLE��
 *    AM_CFG_KEY_ENABLE �� AM_CFG_SOFTIMER_ENABLE ����Ϊ 1������Щ��
 *    �Ѿ�Ĭ������Ϊ 1�� �û������ٴ����á�
 *
 * \par Դ����
 * \snippet demo_miniport_hc595_digitron_key.c src_miniport_hc595_digitron_key
 *
 * \internal
 * \par Modification history
 * - 1.00 15-07-21  tee, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_miniport_hc595_digitron_key
 * \copydoc demo_miniport_hc595_digitron_key.c
 */

/** [src_miniport_hc595_digitron_key] */
#include "ametal.h"
#include "am_vdebug.h"
#include "am_event_input_key.h"
#include "am_hk32f103rbt6_inst_init.h"
#include "demo_std_entries.h"
#include "demo_hk32f103rbt6_core_entries.h"

/**
 * \brief �������
 */
void demo_hk32f103rbt6_core_miniport_hc595_digitron_key_entry (void)
{
    AM_DBG_INFO("demo hk32f103rbt6_core miniport hc595 digitron key!\r\n");

    am_miniport_view_key_595_inst_init();

    demo_std_key_digitron_entry(0);
}
/** [src_miniport_hc595_digitron_key] */

/* end of file */