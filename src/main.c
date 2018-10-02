#include "ZZTest/zz-test.h"
#include "ZZTest/TestZZTest.h"


int main()
{
    TITLE("Test ZZ-Test:");


    TITLE("Test zztest_areEquals:");
    TEST("\tMain success", test_areEquals_mainSuccess);
    TEST("\tInfinity", test_areEquals_infinity);
    TEST("\tNAN", test_areEquals_nan);


    TITLE("Done");
    return 0;
}