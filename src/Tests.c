/*
 * Tests.c
 *
 * Test file that calls the executeFactorial function multiple times with different DEFAULT_VALUE_OF_N.
 *
 */

#include <stdio.h>
#include "StackFrame.h"
#define ZERO 0l
#define THREE 3l
#define TEN 10l

/*
 * Static (akin to "private") function to this module.
 * This function is only ever called by executeFactorialTest below.
 * When it has reached the final recursive call, it
 * calls printStackFrames() to print out stack frame data.
 *
 */

static unsigned long factorialTest(unsigned long default_value, unsigned long n, unsigned long accumulator) {

    if (n <= 1) {
        printStackFrames(default_value + 1);
        return accumulator;
    }
    return factorialTest(default_value, n - 1, n * accumulator);
}

/*
 * Static (akin to "private") function to call factorialTest with set parameter value.
 * and print out the result of calling getBasePointer and getReturnAddress.
 *
 */

static void executeFactorialTest(unsigned long default_value) {
    unsigned long basePointer = getBasePointer();
    printf("executeFactorial: basePointer = %lx\n", basePointer);

    unsigned long returnAddress = getReturnAddress();
    printf("executeFactorial: returnAddress = %lx\n", returnAddress);

    printf("executeFactorial: about to call factorial which should print the stack\n\n");

    unsigned long result = 0l;
    unsigned long number = default_value;
    unsigned long accumulator = 1l;
    result = factorialTest(default_value, number, accumulator);
    printf("executeFactorial: factorial(%lu) = %lu\n", number, result);
}

/*
 * Only testing method, that contains all tests.
 *
 * @return 0
 */
int main() {
    printf("-- TESTING --\n");

    // Testing for larger value of n (n = 10)
    printf("\n1. Testing for larger value of n (n = 10)\n");
    executeFactorialTest(TEN);

    // Testing for smaller value of n (n = 3)
    printf("\n2. Testing for smaller value of n (n = 3)\n");
    executeFactorialTest(THREE);

    // Testing for special value of n (n = 0)
    printf("\n3. Testing for special value of n (n = 0)\n");
    executeFactorialTest(ZERO);

    return 0;
}
