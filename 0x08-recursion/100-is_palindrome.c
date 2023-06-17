#include "main.h"

int check_pal(char *s, int u, int lon);
int _strlen_recursion(char *s);

/**
 * is_palindrome - checks if a string is a palindrome
 *
 * @s: string to reverse
 *
 * Return: 1 if it is, 0 it's not
 */
int is_palindrome(char *s)
{
	if (*s == 0)
	{
		return (1);
	}
	else
	{
		return (check_pal(s, 0, _strlen_recursion(s)));
	}
}

/**
 * _strlen_recursion - returns the length of a string
 *
 * @s: string whose length is to be calculated
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	else
	{
		return (1 + _strlen_recursion(s + 1));
	}
}

/**
 * check_pal - checks the characters recursively for palindromes
 *
 * @s: string to be checked
 *
 * @u: iterator
 *
 * @lon: length of string
 *
 * Return: 1 if palindrome, 0 if not
 */
int check_pal(char *s, int u, int lon)
{
	if (*(s + u) != *(s + lon - 1))
	{
		return (0);
	}
	else if (u >= lon)
	{
		return (1);
	}
	else
	{
		return (check_pal(s, u + 1, lon - 1));
	}
}

