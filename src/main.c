#include "ZZTest/zz-test.h"
#include "ZZTest/TestZZTest.h"


int main()
{
    TITLE("Test zz-test:");


    TITLE("Test zztest_areEquals_double:");
    TEST("\tMain success", test_areEquals_double_mainSuccess);
    TEST("\tInfinity", test_areEquals_double_infinity);
    TEST("\tNAN", test_areEquals_double_nan);

    TITLE("Test zztest_areEquals_intArray:");
    TEST("\tEqual", test_areEquals_intArray_equal);
    TEST("\tUnequal", test_areEquals_intArray_unequal);


    TITLE("Done");
    return 0;
}