#include <math.h>

#include "zz-test.h"
#include "TestZZTest.h"

int test_areEquals_mainSuccess() {
    const double decimalPointsPrecision = 5;
    return
        zztest_areEquals(12.34, 12.34, decimalPointsPrecision)
        && zztest_areEquals(-12.34, -12.34, decimalPointsPrecision)
        && !zztest_areEquals(12.34, -12.34, decimalPointsPrecision)
        && zztest_areEquals(0.0, 0.0, decimalPointsPrecision)
        && zztest_areEquals(-0.0, 0.0, decimalPointsPrecision)
        && zztest_areEquals(-0.0, -0.0, decimalPointsPrecision)

        && zztest_areEquals(12.34000, 12.34001, decimalPointsPrecision)
        && zztest_areEquals(12.34001, 12.34000, decimalPointsPrecision)
        && !zztest_areEquals(12.34000, 12.34002, decimalPointsPrecision)
        && !zztest_areEquals(12.34002, 12.34000, decimalPointsPrecision)
    ;
}
int test_areEquals_infinity() {
    const double decimalPointsPrecision = 5;
    return
        !zztest_areEquals(
            12.34,
            INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            INFINITY,
            12.34,
            decimalPointsPrecision
        )
        && zztest_areEquals(
            INFINITY,
            INFINITY,
            decimalPointsPrecision
        )
        && zztest_areEquals(
            -INFINITY,
            -INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            -INFINITY,
            INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            INFINITY,
            -INFINITY,
            decimalPointsPrecision
        )
    ;
}
int test_areEquals_nan() {
    const double decimalPointsPrecision = 5;
    return
        !zztest_areEquals(
            12.34,
            NAN,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            NAN,
            12.34,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            NAN,
            NAN,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            NAN,
            INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            INFINITY,
            NAN,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            NAN,
            -INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            -INFINITY,
            NAN,
            decimalPointsPrecision
        )
    ;
}