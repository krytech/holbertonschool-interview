#include "palindrome.h"
#include <stdio.h>

/**
 * is_palindrome - Checks if n is a palindrome
 * @n: number to check
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	int remainder = 0;
	unsigned long reversed = 0;
	unsigned long tmp = n;

	while (n != 0)
	{
		remainder = n % 10;

		reversed = reversed * 10 + remainder;

		n /= 10;
	}

	if (reversed == tmp)
		return (1);
	return (0);
}
