//
// Generated by tools/xmega3/time_RTT_calc_clkdiv.sh on Fri Aug 30 10:19:45 AM EDT 2024
//
// This script finds the value for an F_RTT_OSC prescaler that will get G_freq_RTTCLK
// somewhere in the neighborhood of 1000Hz
//
// The macro F_RTT_OSC must be set before calling
// The macros G_freq_RTTCLK, RTC_PRESCALER_1KHz_DIV_gc, and RTC_PERIOD_1KHz_CYC_gc are set
// when done
#undef _BEST_DIFF
#define _BEST_DIFF (F_RTT_OSC+1)

#ifndef F_RTT_OSC
# error "F_RTT_OSC not set"
#endif

#if (F_RTT_OSC / 1UL > 1000UL && (F_RTT_OSC / 1UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 1UL <= 1000UL && 1000UL - (F_RTT_OSC / 1UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV1_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC1_gc
# define G_freq_RTTCLK (F_RTT_OSC / 1UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 2UL > 1000UL && (F_RTT_OSC / 2UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 2UL <= 1000UL && 1000UL - (F_RTT_OSC / 2UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV2_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC2_gc
# define G_freq_RTTCLK (F_RTT_OSC / 2UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 4UL > 1000UL && (F_RTT_OSC / 4UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 4UL <= 1000UL && 1000UL - (F_RTT_OSC / 4UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV4_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC4_gc
# define G_freq_RTTCLK (F_RTT_OSC / 4UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 8UL > 1000UL && (F_RTT_OSC / 8UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 8UL <= 1000UL && 1000UL - (F_RTT_OSC / 8UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV8_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC8_gc
# define G_freq_RTTCLK (F_RTT_OSC / 8UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 16UL > 1000UL && (F_RTT_OSC / 16UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 16UL <= 1000UL && 1000UL - (F_RTT_OSC / 16UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV16_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC16_gc
# define G_freq_RTTCLK (F_RTT_OSC / 16UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 32UL > 1000UL && (F_RTT_OSC / 32UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 32UL <= 1000UL && 1000UL - (F_RTT_OSC / 32UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV32_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC32_gc
# define G_freq_RTTCLK (F_RTT_OSC / 32UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 64UL > 1000UL && (F_RTT_OSC / 64UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 64UL <= 1000UL && 1000UL - (F_RTT_OSC / 64UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV64_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC64_gc
# define G_freq_RTTCLK (F_RTT_OSC / 64UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 128UL > 1000UL && (F_RTT_OSC / 128UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 128UL <= 1000UL && 1000UL - (F_RTT_OSC / 128UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV128_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC128_gc
# define G_freq_RTTCLK (F_RTT_OSC / 128UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 256UL > 1000UL && (F_RTT_OSC / 256UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 256UL <= 1000UL && 1000UL - (F_RTT_OSC / 256UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV256_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC256_gc
# define G_freq_RTTCLK (F_RTT_OSC / 256UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 512UL > 1000UL && (F_RTT_OSC / 512UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 512UL <= 1000UL && 1000UL - (F_RTT_OSC / 512UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV512_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC512_gc
# define G_freq_RTTCLK (F_RTT_OSC / 512UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 1024UL > 1000UL && (F_RTT_OSC / 1024UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 1024UL <= 1000UL && 1000UL - (F_RTT_OSC / 1024UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV1024_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC1024_gc
# define G_freq_RTTCLK (F_RTT_OSC / 1024UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 2048UL > 1000UL && (F_RTT_OSC / 2048UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 2048UL <= 1000UL && 1000UL - (F_RTT_OSC / 2048UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV2048_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC2048_gc
# define G_freq_RTTCLK (F_RTT_OSC / 2048UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 4096UL > 1000UL && (F_RTT_OSC / 4096UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 4096UL <= 1000UL && 1000UL - (F_RTT_OSC / 4096UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV4096_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC4096_gc
# define G_freq_RTTCLK (F_RTT_OSC / 4096UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 8192UL > 1000UL && (F_RTT_OSC / 8192UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 8192UL <= 1000UL && 1000UL - (F_RTT_OSC / 8192UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV8192_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC8192_gc
# define G_freq_RTTCLK (F_RTT_OSC / 8192UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 16384UL > 1000UL && (F_RTT_OSC / 16384UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 16384UL <= 1000UL && 1000UL - (F_RTT_OSC / 16384UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV16384_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC16384_gc
# define G_freq_RTTCLK (F_RTT_OSC / 16384UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif

#if (F_RTT_OSC / 32768UL > 1000UL && (F_RTT_OSC / 32768UL) - 1000UL < _BEST_DIFF) || (F_RTT_OSC / 32768UL <= 1000UL && 1000UL - (F_RTT_OSC / 32768UL) < _BEST_DIFF)
# undef RTC_PRESCALER_DIV_gc
# undef G_freq_RTTCLK
# undef _BEST_DIFF
# define RTC_PRESCALER_1KHz_DIV_gc RTC_PRESCALER_DIV32768_gc
# define RTC_PERIOD_1KHz_CYC_gc RTC_PERIOD_CYC32768_gc
# define G_freq_RTTCLK (F_RTT_OSC / 32768UL)
# if G_freq_RTTCLK > 1000
#  define _BEST_DIFF (G_freq_RTTCLK - 1000UL)
# else
#  define _BEST_DIFF (1000UL - G_freq_RTTCLK)
# endif
#endif
#undef _BEST_DIFF
