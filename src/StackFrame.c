/*
 * StackFrame.c
 *
 * Source file for StackFrame module that provides functionality relating to
 * stack frames and printing out stack frame data.
 *
 */

#include <stdio.h>
#include "StackFrame.h"


/*
 * Non-static (akin to "public") functions that can be called from anywhere.
 * Comments for each function are given in the module interface StackFrame.h
 *
 * At present, they all just return 0 or do nothing.
 *
 * These are the functions you have to implement.
 *
 */

unsigned long getBasePointer() {
    unsigned long base;
    asm("movq %%rbp, %0;" : "=r"(base));
    return base;
}

unsigned long getReturnAddress() {
    return &__builtin_return_address(0);
}

void printStackFrameData(unsigned long basePointer, unsigned long previousBasePointer) {
}

void printStackFrames(int number) {
}
