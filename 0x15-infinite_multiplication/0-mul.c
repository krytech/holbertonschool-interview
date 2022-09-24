#include "holberton.h"

/**
 * _isdigit - checks if string  is a number
 * @str: string to check
 * Return: 0 if a number, 1 if otherwise
 */
int _isdigit(char *str)
{
	int i, digit = 0;

	for (i = 0; str[i] && !digit; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			digit++;
	}
	return (digit);
}

/**
 * _puts - puts in stdout
 * @str: string
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}

/**
 * multiply - multiplies, adds, stores the result in a string.
 * @num1: first number
 * @num2: second number
 * @len1: length of 1st number
 * @len2: length of 2nd number
 * Return: result or error
 */
char *multiply(char *num1, char *num2, int len1, int len2)
{
	char *result = NULL;
	int i, j, carry;
	int len_total = (len1 + len2);

	result = malloc(sizeof(char) * len_total);
	if (!result)
	{
		_puts("Error");
		_putchar('\n');
		exit(98);
	}
	for (i = 0; i < len_total; i++)
		result[i] = '0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			carry += (num1[i] - '0') * (num2[j] - '0');
			carry += result[i + j + 1] - '0';
			result[i + j + 1] = (carry % 10) + '0';
			carry /= 10;
		}
		if (carry)
			result[i + j + 1] = (carry % 10) + '0';
	}
	return (result);
}

/**
 * main - multiplies two positive numbers
 * @val: both number values
 * @counter: arguments count
 * Return: 0 on success, otherwise 98 on failure & error
 */
int main(int counter, char **val)
{
	int len1 = 0, len2 = 0;
	char *num1 = val[1], *num2 = val[2], *result = NULL;

	if (counter != 3 || _isdigit(num1) || _isdigit(num2))
	{
		_puts("Error");
		_putchar('\n');
		exit(98);
	}
	if (val[1][0] == 48 || val[2][0] == 48)
	{
		_puts("0");
		_putchar('\n');
		exit(0);
	}
	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result = multiply(num1, num2, len1, len2);
	if (result[0] == '0')
		_puts(result + 1);
	else
		_puts(result);
	_putchar('\n');
	free(result);
	return (0);
}
