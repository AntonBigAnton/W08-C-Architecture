/*
 * TestFunctions.c
 *
 * Source file for new test functions.
 *
 */

#include <stdio.h>
#include "TestFunctions.h"
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
 * Non-static (akin to "public") function to call factorialTest with set parameter value.
 * and print out the result of calling getBasePointer and getReturnAddress.
 *
 */

void executeFactorialTest(unsigned long default) {
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
