#include <math.h>
#include <limits.h>

#include "zz-test.h"


// <-- Private functions -->
double __zztest_round(double d)
{
    if (d < 0 ) {
        return ceil(d - 0.5);
    }
    return floor(d + 0.5);
}
// </- Private functions -->


// <-- Public functions -->
int zztest_areEquals_double(
    const double expected,
    const double actual,
    const int decimalPointsPrecision
) {
    if (isnan(expected) || isnan(actual)) {
        return 0;
    }
    if (expected == INFINITY) {
        return actual == INFINITY;
    }
    if (expected == -INFINITY) {
        return actual == -INFINITY;
    }

    const double pointShift = pow(10, decimalPointsPrecision);
    const double expectedRounded = __zztest_round(expected * pointShift) / pointShift;
    const double actualRounded = __zztest_round(actual * pointShift) / pointShift;

    const double precision = 1 / pointShift;
    return fabs(expectedRounded - actualRounded) <= precision;
}
int zztest_areEquals_intArray(
    int *expected,
    int *actual,
    const unsigned int length
) {
    for (unsigned int i = 0; i < length; i++) {
        if (expected[i] != actual[i]) {
            return 0;
        }
    }

    return 1;
}
// </- Public functions -->