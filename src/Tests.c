/*
 * Tests.c
 *
 * Test file that calls the executeFactorial function multiple times with different DEFAULT_VALUE_OF_N.
 *
 */

#include <stdio.h>
#include "StackFrame.h"

/*
 * Static (akin to "private") function to this module.
 * This function is only ever called by executeFactorialTest below.
 * When it has reached the final recursive call, it
 * calls printStackFrames() to print out stack frame data.
 *
 */

static unsigned long factorialTest(unsigned long default, unsigned long n, unsigned long accumulator) {

    if (n <= 1) {
        printStackFrames(default + 1);
        return accumulator;
    }
    return factorialTest(default, n - 1, n * accumulator);
}

/*
 * Static (akin to "private") function to call factorialTest with set parameter value.
 * and print out the result of calling getBasePointer and getReturnAddress.
 *
 */

static void executeFactorialTest(unsigned long default) {
    unsigned long basePointer = getBasePointer();
    printf("executeFactorial: basePointer = %lx\n", basePointer);

    unsigned long returnAddress = getReturnAddress();
    printf("executeFactorial: returnAddress = %lx\n", returnAddress);

    printf("executeFactorial: about to call factorial which should print the stack\n\n");

    unsigned long result = 0l;
    unsigned long number = default;
    unsigned long accumulator = 1l;
    result = factorialTest(default, number, accumulator);
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
    executeFactorialTest(10l);

    // Testing for smaller value of n (n = 3)
    printf("\n2. Testing for smaller value of n (n = 3)\n");
    executeFactorialTest(3l);

    // Testing for special value of n (n = 0)
    printf("\n3. Testing for special value of n (n = 0)\n");
    executeFactorialTest(0l);

    return 0;
}
