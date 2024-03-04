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
    asm("movq 0(%%rbp), %0;" : "=r"(base));
    return base;
}

unsigned long getReturnAddress() {
    unsigned long base;
    asm("movq 0(%%rbp), %0;" : "=r"(base));
    unsigned long address;
    asm("movq 8(%1), %0;" : "=r"(address) : "r"(base));
    return address;
}

void printStackFrameData(unsigned long basePointer, unsigned long previousBasePointer) {
    unsigned long frameSize = previousBasePointer - basePointer;
    for (unsigned long j = 0; j < frameSize; j+=8) {
        char base[17];
        sprintf(base, "%016lx", basePointer+j);

        char address[17];
        unsigned long memory;
        asm("movq 0(%1), %0;" : "=r"(memory) : "r"(basePointer+j));
        sprintf(address, "%016lx", memory);
        
        printf("%s: %s  --  ", base, address);
        for (int i = 15; i > 0; i-=2) {
            printf("%c%c    ", base[i], base[i-1]);
        }
        printf("\n");
        
        asm("movq 0(%%rbp), %0;" : "=r"(previousBasePointer));
        
        if (j == 0) {
            printf("-------------\n");
        }
    }
}

void printStackFrames(int number) {
    unsigned long basePointer = getBasePointer();
    for (int i = 0; i <= number; i++) {
        unsigned long previousBasePointer;
        asm("movq 0(%1), %0;" : "=r"(previousBasePointer) : "r"(basePointer));
        printStackFrameData(basePointer, previousBasePointer);
        basePointer = previousBasePointer;
    }
}
