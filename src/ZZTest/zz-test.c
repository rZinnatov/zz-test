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
    const double d1,
    const double d2,
    const int decimalPointsPrecision
) {
    if (isnan(d1) || isnan(d2)) {
        return 0;
    }
    if (d1 == INFINITY) {
        return d2 == INFINITY;
    }
    if (d1 == -INFINITY) {
        return d2 == -INFINITY;
    }

    const double pointShift = pow(10, decimalPointsPrecision);
    const double d1Rounded = __zztest_round(d1 * pointShift) / pointShift;
    const double d2Rounded = __zztest_round(d2 * pointShift) / pointShift;

    const double precision = 1 / pointShift;
    return fabs(d1Rounded - d2Rounded) <= precision;
}
int zztest_areEquals_intArray(
    int *array1,
    int *array2,
    const unsigned int length
) {
    for (unsigned int i = 0; i < length; i++) {
        if (array1[i] != array2[i]) {
            return 0;
        }
    }

    return 1;
}
// </- Public functions -->