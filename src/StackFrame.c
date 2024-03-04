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
    unsigned long address;
    asm("movq 8(%%rbp), %0;" : "=r"(address));
    return address;
}

void printStackFrameData(unsigned long basePointer, unsigned long previousBasePointer) {
    char base[17];
    char address[17];
    sprintf(base, "%016lx", basePointer);
    unsigned long memory;
    asm("movq %1, %0;" : "=r"(memory) : "=r"(basePointer));
    sprintf(address, "%016lx", memory);
    printf("%s: %s  --  ", address, base);
    for (int i = 15; i > 0; i-=2) {
        printf("%c%c    ", base[i], base[i-1]);
    }
    printf("\n");
}

void printStackFrames(int number) {
    unsigned long basePointer = getBasePointer();
    unsigned long previousBasePointer;
    asm("movq 0(%%rbp), %0;" : "=r"(previousBasePointer));
    for (int i = 0; i < number; i++) {
        printStackFrameData(basePointer, previousBasePointer);
        printf("-------------\n");
    }
}
