/*
 * Tests.c
 *
 * Test file that calls the executeFactorial function multiple times with different DEFAULT_VALUE_OF_N.
 *
 */

#include <stdio.h>
#include "StackFrame.h"
#include "Tests.h"

/*
 * Static (akin to "private") function to this module.
 * This function is only ever called by executeFactorialTestTen below.
 * When it has reached the final recursive call, it
 * calls printStackFrames() to print out stack frame data.
 *
 */

static unsigned long factorialTestTen(unsigned long n, unsigned long accumulator) {

    if (n <= 1) {
        printStackFrames(TEN + 1);
        return accumulator;
    }
    return factorialTestTen(n - 1, n * accumulator);
}

/*
 * Static (akin to "private") function to this module.
 * This function is only ever called by executeFactorialTestThree below.
 * When it has reached the final recursive call, it
 * calls printStackFrames() to print out stack frame data.
 *
 */

static unsigned long factorialTestThree(unsigned long n, unsigned long accumulator) {

    if (n <= 1) {
        printStackFrames(THREE + 1);
        return accumulator;
    }
    return factorialTestThree(n - 1, n * accumulator);
}

/*
 * Static (akin to "private") function to this module.
 * This function is only ever called by executeFactorialTestZero below.
 * When it has reached the final recursive call, it
 * calls printStackFrames() to print out stack frame data.
 *
 */

static unsigned long factorialTestZero(unsigned long n, unsigned long accumulator) {

    if (n <= 1) {
        printStackFrames(ZERO + 1);
        return accumulator;
    }
    return factorialTestZero(n - 1, n * accumulator);
}

/*
 * Non-static (akin to "public") function to call factorialTestTen with set parameter value.
 * and print out the result of calling getBasePointer and getReturnAddress.
 *
 */

void executeFactorialTestTen() {
    unsigned long basePointer = getBasePointer();
    printf("executeFactorial: basePointer = %lx\n", basePointer);

    unsigned long returnAddress = getReturnAddress();
    printf("executeFactorial: returnAddress = %lx\n", returnAddress);

    printf("executeFactorial: about to call factorial which should print the stack\n\n");

    unsigned long result = 0l;
    unsigned long number = TEN;
    unsigned long accumulator = 1l;
    result = factorialTestTen(number, accumulator);
    printf("executeFactorial: factorial(%lu) = %lu\n", number, result);
}

/*
 * Non-static (akin to "public") function to call factorialTestThree with set parameter value.
 * and print out the result of calling getBasePointer and getReturnAddress.
 *
 */

void executeFactorialTestThree() {
    unsigned long basePointer = getBasePointer();
    printf("executeFactorial: basePointer = %lx\n", basePointer);

    unsigned long returnAddress = getReturnAddress();
    printf("executeFactorial: returnAddress = %lx\n", returnAddress);

    printf("executeFactorial: about to call factorial which should print the stack\n\n");

    unsigned long result = 0l;
    unsigned long number = THREE;
    unsigned long accumulator = 1l;
    result = factorialTestThree(number, accumulator);
    printf("executeFactorial: factorial(%lu) = %lu\n", number, result);
}

/*
 * Non-static (akin to "public") function to call factorialTestZero with set parameter value.
 * and print out the result of calling getBasePointer and getReturnAddress.
 *
 */

void executeFactorialTestZero() {
    unsigned long basePointer = getBasePointer();
    printf("executeFactorial: basePointer = %lx\n", basePointer);

    unsigned long returnAddress = getReturnAddress();
    printf("executeFactorial: returnAddress = %lx\n", returnAddress);

    printf("executeFactorial: about to call factorial which should print the stack\n\n");

    unsigned long result = 0l;
    unsigned long number = ZERO;
    unsigned long accumulator = 1l;
    result = factorialTestZero(number, accumulator);
    printf("executeFactorial: factorial(%lu) = %lu\n", number, result);
}

/*
 * Main testing method that runs all tests.
 *
 * @return 0
 */
int main() {
    printf("-- TESTING --\n");

    // Testing for larger value of n (n = 10)
    printf("\n1. Testing for larger value of n (n = 10)\n");
    executeFactorialTestTen();

    // Testing for smaller value of n (n = 3)
    printf("\n2. Testing for smaller value of n (n = 3)\n");
    executeFactorialTestThree();

    // Testing for special value of n (n = 0)
    printf("\n3. Testing for special value of n (n = 0)\n");
    executeFactorialTestZero();

    return 0;
}
