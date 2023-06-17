#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 *
 * @n: number whose square root is to be found
 *
 * Return: square root
 */
int actual_sqrt_recursion(int n, int u);
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else
	{
		return (actual_sqrt_recursion(n, 0));
	}
}

/**
 * actual_sqrt_recursion - recurses to obtain natural square root of a number
 *
 * @n: number whose square root is to be found
 *
 * @u: iterator
 *
 * Return: the resulting square root
 */
int actual_sqrt_recursion(int n, int u)
{
	if (u * u > n)
	{
		return (-1);
	}
	else if (u * u == n)
	{
		return (u);
	}
	else
	{
		return (actual_sqrt_recursion(n, u + 1));
	}
}

