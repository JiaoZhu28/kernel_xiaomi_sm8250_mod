/* SPDX-License-Identifier: GPL-2.0 */
/*
 * stock_modules.h - 原厂 4.19.157 内核 /proc/modules 的内容快照
 *
 * 来源：小米原厂内核运行时 cat /proc/modules 的逐行结果（33 行）。
 * 用途：kernel/module.c 中改为返回本常量，使 /proc/modules 看起来与原厂一致，
 *       不暴露“本内核不加载任何外部模块”这一事实。
 */
#ifndef _STOCK_MODULES_H
#define _STOCK_MODULES_H

static const char stock_modules_txt[] =
	"rmnet_perf 36864 0 - Live 0x0000000000000000 (O)\n"
	"rmnet_shs 118784 0 - Live 0x0000000000000000 (O)\n"
	"wlan 7536640 0 - Live 0x0000000000000000 (O)\n"
	"sla 20480 0 - Live 0x0000000000000000 (O)\n"
	"exfat 139264 0 - Live 0x0000000000000000 (O)\n"
	"machine_dlkm 196608 0 - Live 0x0000000000000000 (O)\n"
	"cs35l41_dlkm 147456 2 - Live 0x0000000000000000 (O)\n"
	"wcd938x_slave_dlkm 16384 0 - Live 0x0000000000000000 (O)\n"
	"wcd938x_dlkm 110592 2 machine_dlkm, Live 0x0000000000000000 (O)\n"
	"wcd9xxx_dlkm 57344 19 wcd938x_dlkm, Live 0x0000000000000000 (O)\n"
	"mbhc_dlkm 81920 1 wcd938x_dlkm, Live 0x0000000000000000 (O)\n"
	"tx_macro_dlkm 114688 1 mbhc_dlkm, Live 0x0000000000000000 (O)\n"
	"rx_macro_dlkm 106496 0 - Live 0x0000000000000000 (O)\n"
	"va_macro_dlkm 106496 0 - Live 0x0000000000000000 (O)\n"
	"wsa_macro_dlkm 69632 1 machine_dlkm, Live 0x0000000000000000 (O)\n"
	"swr_ctrl_dlkm 73728 4 tx_macro_dlkm,rx_macro_dlkm,va_macro_dlkm,wsa_macro_dlkm, Live 0x0000000000000000 (O)\n"
	"bolero_cdc_dlkm 57344 6 machine_dlkm,tx_macro_dlkm,rx_macro_dlkm,va_macro_dlkm,wsa_macro_dlkm, Live 0x0000000000000000 (O)\n"
	"wsa881x_dlkm 57344 1 machine_dlkm, Live 0x0000000000000000 (O)\n"
	"wcd_core_dlkm 32768 8 machine_dlkm,wcd938x_dlkm,mbhc_dlkm,tx_macro_dlkm,rx_macro_dlkm,va_macro_dlkm,wsa_macro_dlkm,wsa881x_dlkm, Live 0x0000000000000000 (O)\n"
	"stub_dlkm 16384 1 - Live 0x0000000000000000 (O)\n"
	"hdmi_dlkm 24576 0 - Live 0x0000000000000000 (O)\n"
	"swr_dlkm 24576 4 wcd938x_slave_dlkm,wcd938x_dlkm,swr_ctrl_dlkm,wsa881x_dlkm, Live 0x0000000000000000 (O)\n"
	"pinctrl_lpi_dlkm 24576 6 - Live 0x0000000000000000 (O)\n"
	"pinctrl_wcd_dlkm 16384 0 - Live 0x0000000000000000 (O)\n"
	"usf_dlkm 57344 0 - Live 0x0000000000000000 (O)\n"
	"native_dlkm 200704 0 - Live 0x0000000000000000 (O)\n"
	"platform_dlkm 3051520 62 native_dlkm, Live 0x0000000000000000 (O)\n"
	"q6_dlkm 1146880 11 machine_dlkm,wcd9xxx_dlkm,va_macro_dlkm,swr_ctrl_dlkm,bolero_cdc_dlkm,pinctrl_lpi_dlkm,usf_dlkm,native_dlkm,platform_dlkm, Live 0x0000000000000000 (O)\n"
	"adsp_loader_dlkm 16384 0 - Live 0x0000000000000000 (O)\n"
	"apr_dlkm 233472 4 usf_dlkm,platform_dlkm,q6_dlkm,adsp_loader_dlkm, Live 0x0000000000000000 (O)\n"
	"snd_event_dlkm 16384 5 machine_dlkm,bolero_cdc_dlkm,pinctrl_lpi_dlkm,q6_dlkm,apr_dlkm, Live 0x0000000000000000 (O)\n"
	"q6_notifier_dlkm 16384 3 pinctrl_lpi_dlkm,q6_dlkm,apr_dlkm, Live 0x0000000000000000 (O)\n"
	"q6_pdr_dlkm 16384 1 q6_notifier_dlkm, Live 0x0000000000000000 (O)\n";

#endif /* _STOCK_MODULES_H */
