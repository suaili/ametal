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
 * \brief FM175XX 配置文件
 * \sa am_hwconf_fm175xx.c
 *
 * \internal
 * \par Modification history
 * - 1.00 17-07-13  tee, first implementation.
 * \endinternal
 */
#include "ametal.h"
#include "am_fm175xx.h"
#include "kl26_pin.h"
#include "am_kl26_inst_init.h"

/**
 * \addtogroup am_if_src_hwconf_fm175xx
 * \copydoc am_hwconf_fm175xx.c
 * @{
 */

/* 定义 fm175xx 实例 */
static am_fm175xx_dev_t  __g_fm175xx_dev;

/* 配置FM175xx LPCD模式参数 */
am_local am_const am_fm175xx_lpcd_cfginfo_t  __g_lpcd_cfg_info = {
    AM_FM175XX_LCPD_SLEEP500MS,
    AM_FM175XX_LCPD_DETECT47US,
    AM_FM175XX_LCPD_TX2_RF_ENABLE,
    AM_FM175XX_LCPD_RF_NMOS_23,
    AM_FM175XX_LCPD_RF_PMOS_1,
    0.07,
    AM_FM175XX_LCPD_AUTO_DETECT_TIMES_1,
    AM_FM175XX_LCPD_INT_ENABLE,
    AM_FM175XX_LCPD_AUTO_WUP_ENABLE,
    AM_FM175XX_LCPD_AUTO_WUP_TIME_432MIN,
};

/* 定义 fm175xx 实例信息 */
am_local am_const am_fm175xx_devinfo_t __g_fm175xx_devinfo = {
    PIOE_1,
    PIOE_16,
    PIOC_1,
    AM_FM175XX_PROT_TYPE_ISO14443A_106,
//    &__g_lpcd_cfg_info        //若需要开启LPCD功能则需要取消此行注释
};


am_fm175xx_handle_t am_fm175xx_inst_init (void)
{
      am_fm175xx_init(&__g_fm175xx_dev,
                       (am_spi_handle_t)am_kl26_spi0_poll_inst_init(),
                      &__g_fm175xx_devinfo);

      return &__g_fm175xx_dev;
}

/**
 * @}
 */

/* end of file */
