#pragma once


#ifdef __cplusplus
extern "C" {
#endif


int test_areEquals_double_mainSuccess();
int test_areEquals_double_infinity();
int test_areEquals_double_nan();

int test_areEquals_intArray_equal();
int test_areEquals_intArray_unequal();


#ifdef __cplusplus
}
#endif