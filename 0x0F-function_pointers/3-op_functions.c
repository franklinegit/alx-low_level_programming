#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - returns sum of two integers
 * @a: input integer
 * @b: input integer
 * Return: sum
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - returns difference of two integers
 * @a: input integer
 * @b: input integer
 * Return: difference
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - returns product of two integers
 * @a: input integer
 * @b: input integer
 * Return: product
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - returns quotient of two integers
 * @a: input integer
 * @b: input integer
 * Return: quotient
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - returns remainder of division
 * @a: input integer
 * @b: input integer
 * Return: remainder
 */
int op_mod(int a, int b)
{
	return (a % b);
}
