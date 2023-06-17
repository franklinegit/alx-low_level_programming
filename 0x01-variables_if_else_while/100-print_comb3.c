#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int d, r;

	for (d = 48; d <= 56; d++)
	{
		for (r = 49; r <= 57; r++)
		{
			if (r > d)
			{
				putchar(d);
				putchar(r);
				if (d != 56 || r != 57)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}

