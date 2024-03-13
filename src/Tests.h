/*
 * Factorial.h
 *
 * Header file for the testing.
 *
 */

#ifndef TESTS_H_
#define TESTS_H_

/*
 * The numbers to use when computing factorial.
 */
#define ZERO 0l
#define THREE 3l
#define TEN 10l

/*
 * Executes a recursive factorial function for n = 10 and prints out its own base pointer, return address
 * and a number of stack frames starting at the final recursive call to the factorial function.
 */
void executeFactorialTen();

/*
 * Executes a recursive factorial function for n = 3 and prints out its own base pointer, return address
 * and a number of stack frames starting at the final recursive call to the factorial function.
 */
void executeFactorialThree();

/*
 * Executes a recursive factorial function for n = 0 and prints out its own base pointer, return address
 * and a number of stack frames starting at the final recursive call to the factorial function.
 */
void executeFactorialZero();

#endif /* TESTS_H_ */
