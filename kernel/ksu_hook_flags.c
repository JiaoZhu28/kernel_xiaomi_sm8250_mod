// SPDX-License-Identifier: GPL-2.0
/*
 * 手动钩子开关变量。
 *
 * 本内核树在 fs/exec.c、fs/read_write.c、drivers/input/input.c 里
 * 写入了手动集成（manual hook）调用点，形如：
 *
 *     if (unlikely(ksu_execveat_hook))
 *             ksu_handle_execveat(&fd, &filename, &argv, &envp, &flags);
 *
 * 这三个 bool 原本由 SukiSU 系的 KSU 内核代码定义；官方 KernelSU
 * （v0.9.5 及以后）只走 kprobe 路径，不定义它们，导致链接期
 * undefined symbol。
 *
 * 这里统一提供并置为 true，使树里的调用点生效，直接调用 KSU 的
 * ksu_handle_* 处理函数（这些函数在 v0.9.5 中存在且不依赖 kprobe）。
 */

#include <linux/types.h>
#include <linux/cache.h>

bool ksu_execveat_hook __read_mostly = true;
bool ksu_vfs_read_hook __read_mostly = true;
bool ksu_input_hook __read_mostly = true;
