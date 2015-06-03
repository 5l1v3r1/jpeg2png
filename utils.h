#ifndef JPEG2PNG_UTILS_H
#define JPEG2PNG_UTILS_H

#include <stdnoreturn.h>
#include <time.h>

noreturn void die(const char *msg, ...);
clock_t start_timer(const char *name);
void stop_timer(clock_t t, const char *n);

#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#define CLAMP(x, low, high) (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
#define DUMP(v, f) do { printf( #v " = " f "\n", v); } while(false)

#define START_TIMER(n) clock_t macro_timer_##n = start_timer(#n);
#define STOP_TIMER(n) stop_timer(macro_timer_##n, #n);

#endif
