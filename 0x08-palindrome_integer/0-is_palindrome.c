#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given
 * unsigned integer is a palindrome.
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long a = n, pow;

	for (pow = 1; a >= 1; pow *= 10)
		a = a / 10;
	pow /= 10;
	while (pow > 1)
	{
		if (n / pow != n % 10)
			return (0);
		n = (n % pow) / 10;
		pow /= 100;
	}
	return (1);
}
