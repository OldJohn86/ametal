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
 * \brief ZML165 GPIO �û������ļ���
 * \sa am_hwconf_zml165_gpio.c
 * 
 * \internal
 * \par Modification history
 * - 1.00 17-04-12  nwt, first implementation.
 * \endinternal
 */

#include "am_zml165.h"
#include "am_gpio.h"
#include "am_zml165_gpio.h"
#include "hw/amhw_zlg_gpio.h"
#include "am_zml165_clk.h"

/**
 * \addtogroup am_if_src_hwconf_zml165_gpio
 * \copydoc am_hwconf_zml165_gpio.c
 * @{
 */

/** \brief GPIOƽ̨��ʼ�� */
void __zml165_plfm_gpio_init (void)
{

    /* ʹ��GPIO�������ʱ�� */

    /* ����GPIO�����˿�ʱ�� */
    am_clk_enable(CLK_GPIOA );
    am_clk_enable(CLK_GPIOB);
    am_clk_enable(CLK_GPIOC);
    am_clk_enable(CLK_GPIOD);

    /* ϵͳ����ʱ��ʹ��(�ȼ���AFIOʱ��) */
    am_clk_enable(CLK_SYSCFG);

    /* ��λGPIO������� */
    am_zml165_clk_reset(CLK_GPIOA);
    am_zml165_clk_reset(CLK_GPIOB);
    am_zml165_clk_reset(CLK_GPIOC);
    am_zml165_clk_reset(CLK_GPIOD);
    am_zml165_clk_reset(CLK_SYSCFG);
}

/** \brief GPIOƽ̨ȥ��ʼ�� */
void __zml165_plfm_gpio_deinit (void)
{

    /* ��λGPIO������� */
    am_zml165_clk_reset(CLK_GPIOA);
    am_zml165_clk_reset(CLK_GPIOB);
    am_zml165_clk_reset(CLK_GPIOC);
    am_zml165_clk_reset(CLK_GPIOD);
    am_zml165_clk_reset(CLK_SYSCFG);

    /* ����GPIO�������ʱ�� */

    /* ����GPIO�����˿�ʱ�� */
    am_clk_disable(CLK_GPIOA);
    am_clk_disable(CLK_GPIOB);
    am_clk_disable(CLK_GPIOC);
    am_clk_disable(CLK_GPIOD);

    /* ϵͳ����ʱ�ӽ���(�ȼ���AFIOʱ��) */
    am_clk_disable(CLK_SYSCFG);
}

/** \brief ���Ŵ�����Ϣ�ڴ� */
static struct am_zml165_gpio_trigger_info __g_gpio_triginfos[PIN_INT_MAX];

/** \brief ���Ŵ�����Ϣӳ�� */
static uint8_t __g_gpio_infomap[PIN_INT_MAX];

/** \brief GPIO�豸��Ϣ */
const am_zml165_gpio_devinfo_t __g_gpio_devinfo = {
     ZML165_GPIO_BASE,          /**< \brief GPIO�������Ĵ������ַ */
     ZML165_SYSCFG_BASE,        /**< \brief SYSCFG���üĴ������ַ */
     ZML165_EXTI_BASE,          /**< \brief �ⲿ�¼��������Ĵ������ַ */

     {
          INUM_EXTI0_1,         /**< \brief �ⲿ�ж���0����1 */
          INUM_EXTI2_3,         /**< \brief �ⲿ�ж���2����3 */
          INUM_EXTI4_15         /**< \brief �ⲿ�ж���4����15 */
     },

     PIN_INT_MAX,               /**< \brief GPIO֧�ֵ������жϺ����� */
    __g_gpio_infomap,           /**< \brief ���Ŵ�����Ϣӳ�� */
    __g_gpio_triginfos,         /**< \brief ���Ŵ�����Ϣ�ڴ� */
    __zml165_plfm_gpio_init,
    __zml165_plfm_gpio_deinit
};

/** \brief GPIO�豸ʵ�� */
am_zml165_gpio_dev_t __g_gpio_dev;

/** \brief GPIO ʵ����ʼ�� */
int am_zml165_gpio_inst_init (void)
{
    return am_zml165_gpio_init(&__g_gpio_dev, &__g_gpio_devinfo);
}

/** \brief GPIO ʵ�����ʼ�� */
void am_zml165_gpio_inst_deinit (void)
{
    am_zml165_gpio_deinit();
}


/**
 * @}
 */

/* end of file */