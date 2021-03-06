#ifndef _PERF_UI_SLANG_H_
#define _PERF_UI_SLANG_H_ 1
#include <features.h>
#ifndef HAVE_LONG_LONG
#define HAVE_LONG_LONG __GLIBC_HAVE_LONG_LONG
#endif
#include <slang.h>

#if SLANG_VERSION < 20104
#define slsmg_printf(msg, args...) \
	SLsmg_printf((char *)(msg), ##args)
#define slsmg_write_nstring(msg, len) \
	SLsmg_write_nstring((char *)(msg), len)
#define sltt_set_color(obj, name, fg, bg) \
	SLtt_set_color(obj,(char *)(name), (char *)(fg), (char *)(bg))
#else
#define slsmg_printf SLsmg_printf
#define slsmg_write_nstring SLsmg_write_nstring
#define sltt_set_color SLtt_set_color
#endif

#define SL_KEY_UNTAB 0x1000

#endif 
