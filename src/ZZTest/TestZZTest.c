#include <math.h>

#include "zz-test.h"
#include "TestZZTest.h"

int test_areEquals_double_mainSuccess() {
    const double decimalPointsPrecision = 5;
    return
        zztest_areEquals_double(12.34, 12.34, decimalPointsPrecision)
        && zztest_areEquals_double(-12.34, -12.34, decimalPointsPrecision)
        && !zztest_areEquals_double(12.34, -12.34, decimalPointsPrecision)
        && zztest_areEquals_double(0.0, 0.0, decimalPointsPrecision)
        && zztest_areEquals_double(-0.0, 0.0, decimalPointsPrecision)
        && zztest_areEquals_double(-0.0, -0.0, decimalPointsPrecision)

        && zztest_areEquals_double(12.34000, 12.34001, decimalPointsPrecision)
        && zztest_areEquals_double(12.34001, 12.34000, decimalPointsPrecision)
        && !zztest_areEquals_double(12.34000, 12.34002, decimalPointsPrecision)
        && !zztest_areEquals_double(12.34002, 12.34000, decimalPointsPrecision)
    ;
}
int test_areEquals_double_infinity() {
    const double decimalPointsPrecision = 5;
    return
        !zztest_areEquals_double(
            12.34,
            INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals_double(
            INFINITY,
            12.34,
            decimalPointsPrecision
        )
        && zztest_areEquals_double(
            INFINITY,
            INFINITY,
            decimalPointsPrecision
        )
        && zztest_areEquals_double(
            -INFINITY,
            -INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals_double(
            -INFINITY,
            INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals_double(
            INFINITY,
            -INFINITY,
            decimalPointsPrecision
        )
    ;
}
int test_areEquals_double_nan() {
    const double decimalPointsPrecision = 5;
    return
        !zztest_areEquals_double(
            12.34,
            NAN,
            decimalPointsPrecision
        )
        && !zztest_areEquals_double(
            NAN,
            12.34,
            decimalPointsPrecision
        )
        && !zztest_areEquals_double(
            NAN,
            NAN,
            decimalPointsPrecision
        )
        && !zztest_areEquals_double(
            NAN,
            INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals_double(
            INFINITY,
            NAN,
            decimalPointsPrecision
        )
        && !zztest_areEquals_double(
            NAN,
            -INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals_double(
            -INFINITY,
            NAN,
            decimalPointsPrecision
        )
    ;
}

int test_areEquals_intArray_equal() {
    int array1[] = { 1, 2, 3, 4 };
    int array2[] = { 1, 2, 3, 4 };

    return zztest_areEquals_intArray(array1, array2, 4) == 1;
}
int test_areEquals_intArray_unequal() {
    int array1[] = { 1, 5, 3, 4 };
    int array2[] = { 1, 2, 3, 4 };

    return zztest_areEquals_intArray(array1, array2, 4) == 0;
}