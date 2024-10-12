//
// Generated by tools/xmega3/time_TCA_calc_exact.sh on Sat Sep 21 06:28:38 PM EDT 2024
//
// This script requires the following macros to be set:
//    TIMER_CLOCK: The base clock rate of the timer
//    TIMER_HZ   : The desired frequency of the timer signal
//    COUNTER_MAX: The maximum value of the timer's counter
//
// This script sets the following macros:
//    TIMER_TOP  : The value of the timer's PER register
//    TIMER_PSC  : The value of the CLKSEL bits in the timer's CTRLA register
//    TIMER_ERROR: The difference between the frequency given by the selected
//                 values and the desired frequency
//
#undef DONE
#undef TIMER_ERROR

#define TIMER_ERROR (TIMER_HZ)


#if (TIMER_CLOCK / TIMER_HZ) < 1
# error "Unable to calculate timer values, input clock too slow"
# define DONE 1
#endif

#if !defined(DONE) && ((TIMER_CLOCK/(TIMER_HZ * 1)) < COUNTER_MAX + 1)
# if (TIMER_CLOCK % (TIMER_HZ * 1)) < TIMER_ERROR
#  undef TIMER_ERROR
#  undef TIMER_TOP
#  undef TIMER_PSC

#  define TIMER_ERROR (TIMER_CLOCK % (TIMER_HZ * 1U))
#  define TIMER_TOP ((TIMER_CLOCK / (TIMER_HZ * 1U)) - 1U)
#  define TIMER_PSC (TCA_SINGLE_CLKSEL_DIV1_gc)

#  if TIMER_ERROR == 0
#   define DONE 1
#  endif
# endif
#endif

#if !defined(DONE) && ((TIMER_CLOCK/(TIMER_HZ * 2)) < COUNTER_MAX + 1)
# if (TIMER_CLOCK % (TIMER_HZ * 2)) < TIMER_ERROR
#  undef TIMER_ERROR
#  undef TIMER_TOP
#  undef TIMER_PSC

#  define TIMER_ERROR (TIMER_CLOCK % (TIMER_HZ * 2U))
#  define TIMER_TOP ((TIMER_CLOCK / (TIMER_HZ * 2U)) - 1U)
#  define TIMER_PSC (TCA_SINGLE_CLKSEL_DIV2_gc)

#  if TIMER_ERROR == 0
#   define DONE 1
#  endif
# endif
#endif

#if !defined(DONE) && ((TIMER_CLOCK/(TIMER_HZ * 4)) < COUNTER_MAX + 1)
# if (TIMER_CLOCK % (TIMER_HZ * 4)) < TIMER_ERROR
#  undef TIMER_ERROR
#  undef TIMER_TOP
#  undef TIMER_PSC

#  define TIMER_ERROR (TIMER_CLOCK % (TIMER_HZ * 4U))
#  define TIMER_TOP ((TIMER_CLOCK / (TIMER_HZ * 4U)) - 1U)
#  define TIMER_PSC (TCA_SINGLE_CLKSEL_DIV4_gc)

#  if TIMER_ERROR == 0
#   define DONE 1
#  endif
# endif
#endif

#if !defined(DONE) && ((TIMER_CLOCK/(TIMER_HZ * 8)) < COUNTER_MAX + 1)
# if (TIMER_CLOCK % (TIMER_HZ * 8)) < TIMER_ERROR
#  undef TIMER_ERROR
#  undef TIMER_TOP
#  undef TIMER_PSC

#  define TIMER_ERROR (TIMER_CLOCK % (TIMER_HZ * 8U))
#  define TIMER_TOP ((TIMER_CLOCK / (TIMER_HZ * 8U)) - 1U)
#  define TIMER_PSC (TCA_SINGLE_CLKSEL_DIV8_gc)

#  if TIMER_ERROR == 0
#   define DONE 1
#  endif
# endif
#endif

#if !defined(DONE) && ((TIMER_CLOCK/(TIMER_HZ * 16)) < COUNTER_MAX + 1)
# if (TIMER_CLOCK % (TIMER_HZ * 16)) < TIMER_ERROR
#  undef TIMER_ERROR
#  undef TIMER_TOP
#  undef TIMER_PSC

#  define TIMER_ERROR (TIMER_CLOCK % (TIMER_HZ * 16U))
#  define TIMER_TOP ((TIMER_CLOCK / (TIMER_HZ * 16U)) - 1U)
#  define TIMER_PSC (TCA_SINGLE_CLKSEL_DIV16_gc)

#  if TIMER_ERROR == 0
#   define DONE 1
#  endif
# endif
#endif

#if !defined(DONE) && ((TIMER_CLOCK/(TIMER_HZ * 64)) < COUNTER_MAX + 1)
# if (TIMER_CLOCK % (TIMER_HZ * 64)) < TIMER_ERROR
#  undef TIMER_ERROR
#  undef TIMER_TOP
#  undef TIMER_PSC

#  define TIMER_ERROR (TIMER_CLOCK % (TIMER_HZ * 64U))
#  define TIMER_TOP ((TIMER_CLOCK / (TIMER_HZ * 64U)) - 1U)
#  define TIMER_PSC (TCA_SINGLE_CLKSEL_DIV64_gc)

#  if TIMER_ERROR == 0
#   define DONE 1
#  endif
# endif
#endif

#if !defined(DONE) && ((TIMER_CLOCK/(TIMER_HZ * 256)) < COUNTER_MAX + 1)
# if (TIMER_CLOCK % (TIMER_HZ * 256)) < TIMER_ERROR
#  undef TIMER_ERROR
#  undef TIMER_TOP
#  undef TIMER_PSC

#  define TIMER_ERROR (TIMER_CLOCK % (TIMER_HZ * 256U))
#  define TIMER_TOP ((TIMER_CLOCK / (TIMER_HZ * 256U)) - 1U)
#  define TIMER_PSC (TCA_SINGLE_CLKSEL_DIV256_gc)

#  if TIMER_ERROR == 0
#   define DONE 1
#  endif
# endif
#endif

#if !defined(DONE) && ((TIMER_CLOCK/(TIMER_HZ * 1024)) < COUNTER_MAX + 1)
# if (TIMER_CLOCK % (TIMER_HZ * 1024)) < TIMER_ERROR
#  undef TIMER_ERROR
#  undef TIMER_TOP
#  undef TIMER_PSC

#  define TIMER_ERROR (TIMER_CLOCK % (TIMER_HZ * 1024U))
#  define TIMER_TOP ((TIMER_CLOCK / (TIMER_HZ * 1024U)) - 1U)
#  define TIMER_PSC (TCA_SINGLE_CLKSEL_DIV1024_gc)

#  if TIMER_ERROR == 0
#   define DONE 1
#  endif
# endif
#endif

#if TIMER_ERROR == TIMER_HZ
# error "Unable to calculate timer values, input clock likely too fast"
#endif
#undef DONE