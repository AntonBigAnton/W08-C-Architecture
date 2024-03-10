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
    // Get the base pointer in the stack frame of the function that called getBasePointer
    asm("movq 0(%%rbp), %0;" : "=r"(base));
    return base;
}

unsigned long getReturnAddress() {
    unsigned long base;
    // Get the base pointer in the stack frame of the function that called getReturnAddress
    asm("movq 0(%%rbp), %0;" : "=r"(base));
    unsigned long address;
    // Get the return address in the stack frame of the function that called getReturnAddress using its base pointer
    asm("movq 8(%1), %0;" : "=r"(address) : "r"(base));
    return address;
}

void printStackFrameData(unsigned long basePointer, unsigned long previousBasePointer) {
    // Calculate the size of the stack frame
    unsigned long frameSize = previousBasePointer - basePointer;
    // Loop for every multiple of 8 in the stack frame size (the difference in bits)
    for (unsigned long j = 0; j < frameSize; j+=BYTES_PER_LINE) {
        // Format the base pointer
        char base[17];
        sprintf(base, "%016lx", basePointer+j);

        char address[17];
        unsigned long value;
        // Get the value stored at the base pointer
        asm("movq 0(%1), %0;" : "=r"(value) : "r"(basePointer+j));
        // Format the value
        sprintf(address, "%016lx", value);
        
        // Print out both hexadecimal numbers in the required format 
        printf("%s: %s  --  ", base, address);
        // Cycle through the address value in reverse order, 2 digits at a time
        for (int i = 15; i > 0; i-=2) {
            printf("%c%c    ", address[i], address[i-1]);
        }
        printf("\n");
        
        // Update the previousBasePointer
        asm("movq 0(%%rbp), %0;" : "=r"(previousBasePointer));
        
        // Print out a line of '-' only after the first iteration
        if (j == 0) {
            printf("-------------\n");
        }
    }
}

void printStackFrames(int number) {
    // Initialise the base pointer to the base pointer in the stack frame of the function that called getBasePointer
    unsigned long basePointer = getBasePointer();
    for (int i = 0; i <= number; i++) {
        unsigned long previousBasePointer;
        // Set the previousBasePointer to the previous value of basePointer
        asm("movq 0(%1), %0;" : "=r"(previousBasePointer) : "r"(basePointer));
        // Print the stack frame's data
        printStackFrameData(basePointer, previousBasePointer);
        // Set the base pointer to the previousBasePointer
        basePointer = previousBasePointer;
    }
}
