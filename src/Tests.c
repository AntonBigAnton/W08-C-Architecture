/*
 * Tests.c
 *
 * Test file that calls the executeFactorial function multiple times with different DEFAULT_VALUE_OF_N.
 *
 */

#include <stdio.h>
#include "StackFrame.h"
#include "Factorial.h"
#undef DEFAULT_VALUE_OF_N

/*
 * Only testing method, that contains all tests.
 *
 * @return 0
 */
int main() {
    printf("TESTING\n");

    // Testing for larger value of n (n = 10)
    printf("\n-- 1. Testing for larger value of n (n = 10) --\n");
    
    unsigned long DEFAULT_VALUE_OF_N = 10l;
    executeFactorial();

    // Testing for smaller value of n (n = 3)
    /*printf("\n-- 2. Testing for smaller value of n (n = 3) --\n");
    #undef DEFAULT_VALUE_OF_N
    #define DEFAULT_VALUE_OF_N 3l
    executeFactorial();

    // Testing for special value of n (n = 0)
    printf("\n-- 3. Testing for special value of n (n = 0) --\n");
    #undef DEFAULT_VALUE_OF_N
    #define DEFAULT_VALUE_OF_N 0l
    executeFactorial();

    // Testing for negative value of n (n = -1)
    printf("\n-- 4. Testing for special value of n (n = -1) --\n");
    #undef DEFAULT_VALUE_OF_N
    #define DEFAULT_VALUE_OF_N -1l
    executeFactorial();*/
    return 0;
}
