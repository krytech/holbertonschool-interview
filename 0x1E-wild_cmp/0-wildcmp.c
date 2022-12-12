#include "holberton.h"

/**
* wildcmp - compares two strings to see if they are identical
* @s1: pointer to first string
* @s2: pointer to second string
* Return: 1 if the strings is identical, otherwise 0
*/
int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (!*s2);
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
