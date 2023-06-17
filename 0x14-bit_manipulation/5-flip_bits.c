#include "main.h"

/**
 * flip_bits - function returning number of bits to be flipped
 * @n: number
 * @m: number
 * Return: number of bits you would need to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int num, excl = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		num = excl >> i;
		if (num & 1)
			count++;
	}
	return (count);
}
