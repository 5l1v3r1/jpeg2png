#ifndef JPEG2PNG_UTILS_H
#define JPEG2PNG_UTILS_H

#include <assert.h>
#include <stdnoreturn.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

noreturn void die(const char *msg, ...);
noreturn void die_perror(const char *msg, ...);
clock_t start_timer(const char *name);
void stop_timer(clock_t t, const char *n);

#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#define CLAMP(x, low, high) (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
#define DUMP(v, f) do { printf( #v " = " f "\n", v); } while(false)
#if defined(NDEBUG) && defined(BUILTIN_UNREACHABLE)
  #define ASSUME(x) do { if(!(x)) { __builtin_unreachable(); } } while(false)
#else
  #define ASSUME(x) assert(x)
#endif
#if defined(NDEBUG) && defined(BUILTIN_ASSUME_ALIGNED)
  #define ASSUME_ALIGNED(x) x = __builtin_assume_aligned(x, 16)
#else
  #define ASSUME_ALIGNED(x) ASSUME((((uintptr_t)p) & 15) == 0)
#endif

#define START_TIMER(n) clock_t macro_timer_##n = start_timer(#n);
#define STOP_TIMER(n) stop_timer(macro_timer_##n, #n);

inline void check(unsigned x, unsigned y, unsigned w, unsigned h) {
        ASSUME(x < w);
        ASSUME(y < h);
        (void) x;
        (void) y;
        (void) w;
        (void) h;
}

inline float *p(float *in, unsigned x, unsigned y, unsigned w, unsigned h) {
        check(x, y, w, h);
        return &in[y * w + x];
}

inline float a(unsigned n) {
        if(n == 0) {
                return 1./sqrt(2.);
        } else {
                return 1.;
        }
}

inline float sqr(float x) {
        return x * x;
}

#endif
