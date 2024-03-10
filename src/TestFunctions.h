/*
 * TestFunctions.h
 *
 * Header file for test functions implementation.
 *
 */

#ifndef SRC_TEST_H_
#define SRC_TEST_H_

/*
 * Executes a recursive factorial function and prints out its own base pointer, return address
 * and a number of stack frames starting at the final recursive call to the factorial function.
 * 
 * @param default The inputted value of n (replaces DEFAULT_VALUE_OF_N)
 */
void executeFactorialTest(unsigned long default);

#endif /* SRC_TEST_H_ */