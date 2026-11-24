/*
 * kernel/configs.c
 * Echo the kernel .config file used to build the kernel
 *
 * Copyright (C) 2002 Khalid Aziz <khalid_aziz@hp.com>
 * Copyright (C) 2002 Randy Dunlap <rdunlap@xenotime.net>
 * Copyright (C) 2002 Al Stone <ahs3@fc.hp.com>
 * Copyright (C) 2002 Hewlett-Packard Company
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
 * NON INFRINGEMENT.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/init.h>
#include <linux/uaccess.h>

/**************************************************/
/* the actual current config file                 */

/*
 * Define kernel_config_data and kernel_config_data_size, which contains the
 * wrapped and compressed configuration file.  The file is first compressed
 * with gzip and then bounded by two eight byte magic numbers to allow
 * extraction from a binary kernel image:
 *
 *   IKCFG_ST
 *   <image>
 *   IKCFG_ED
 */
#define MAGIC_START	"IKCFG_ST"
#define MAGIC_END	"IKCFG_ED"
#include "config_data.h"


#define MAGIC_SIZE (sizeof(MAGIC_START) - 1)
#define kernel_config_data_size \
	(sizeof(kernel_config_data) - 1 - MAGIC_SIZE * 2)

#ifdef CONFIG_IKCONFIG_PROC

/*
 * Miniinit fork: /proc/config.gz 返回原厂配置的原始 gzip 字节。
 *
 * 原因：
 *   1. 本内核启用 KSU/SUSFS，真实配置里 CONFIG_KSU=y 等行会直接暴露
 *   2. 本内核关闭了 MODVERSIONS、拒绝外部模块，这些差异同样写在配置里
 *   3. 内核内没有 zlib，无法在读取时解压再过滤，只能预先备好字节
 *
 * stock_config_gz.h 的 blob 取自官方 boot.img 内核的 IKCFG_ST/IKCFG_ED 区间，
 * 与小米出厂内核通过 /proc/config.gz 暴露的内容逐字节一致。
 */
#include "stock_config_gz.h"

static ssize_t
ikconfig_read_current(struct file *file, char __user *buf,
		      size_t len, loff_t * offset)
{
	return simple_read_from_buffer(buf, len, offset,
				       stock_config_gz,
				       stock_config_gz_len);
}

static const struct file_operations ikconfig_file_ops = {
	.owner = THIS_MODULE,
	.read = ikconfig_read_current,
	.llseek = default_llseek,
};

static int __init ikconfig_init(void)
{
	struct proc_dir_entry *entry;

	/* create the current config file */
	entry = proc_create("config.gz", S_IFREG | S_IRUGO, NULL,
			    &ikconfig_file_ops);
	if (!entry)
		return -ENOMEM;

	proc_set_size(entry, stock_config_gz_len);

	return 0;
}

static void __exit ikconfig_cleanup(void)
{
	remove_proc_entry("config.gz", NULL);
}

module_init(ikconfig_init);
module_exit(ikconfig_cleanup);

#endif /* CONFIG_IKCONFIG_PROC */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Randy Dunlap");
MODULE_DESCRIPTION("Echo the kernel .config file used to build the kernel");
