#pragma once

#include <stdio.h>

// <-- Macroses -->
#define TITLE(str) printf("\x1b[1m" str "\x1b[0m\n")
#define PASSED "\x1b[32mPassed\x1b[0m"
#define FAILED "\x1b[31mFailed\x1b[0m"
#define TEST(name, method) printf( \
    "\t%s: %s\n", \
    name, \
    method() ? PASSED : FAILED \
);
// </- Macroses -->


// <-- Functions -->
#ifdef __cplusplus
extern "C" {
#endif


int zztest_areEquals_double(
    const double expected,
    const double actual,
    const int decimalPointsPrecision
);
int zztest_areEquals_intArray(
    int *expected,
    int *actual,
    const unsigned int length
);


#ifdef __cplusplus
}
#endif
// </- Functions -->