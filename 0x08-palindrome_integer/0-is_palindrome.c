#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - Checks wheter integer is a palindrome
 * or not
 * @n: Number to be checked
 * Returns: return 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long r = 0, on = n;

	while (n != 0)
	{
		r = r * 10 + (n % 10);
		n /= 10;
	}
	if (on == n % 10)
		return (1);
	else
		return (0);
}
