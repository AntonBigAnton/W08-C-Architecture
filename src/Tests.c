/*
 * Tests.c
 *
 * Test file that calls the executeFactorial function multiple times with different DEFAULT_VALUE_OF_N.
 *
 */

#include <stdio.h>
#include "StackFrame.h"
#include "TestFunctions.h"

/*
 * Only testing method, that contains all tests.
 *
 * @return 0
 */
int main() {
    printf("-- TESTING --\n");

    // Testing for larger value of n (n = 10)
    printf("\n1. Testing for larger value of n (n = 10)\n");
    executeFactorialTest(10l);

    // Testing for smaller value of n (n = 3)
    printf("\n2. Testing for smaller value of n (n = 3)\n");
    executeFactorialTest(3l);

    // Testing for special value of n (n = 0)
    printf("\n3. Testing for special value of n (n = 0)\n");
    executeFactorialTest(0l);

    return 0;
}
