#include "menger.h"

/**
 * pchar - determines char to print '#' or ' '
 * @r: row idx
 * @c: column idx
 *
 * Return: '#' or ' '
 */
char pchar(size_t r, size_t c)
{
	while (r && c)
	{
		if (r % 3 == 1 && c % 3 == 1)
			return (' ');
		r /= 3, c /= 3;
	}
	return ('#');
}

/**
 * menger - draws a 2D Menger sponge
 * @level: level of Menger sponge to draw
 *
 * Return: None
 */
void menger(int level)
{
	size_t size, r, c;

	if (level < 0)
		return;
	size = pow(3, level);
	for (r = 0; r < size; ++r)
	{
		for (c = 0; c < size; ++c)
			putchar(pchar(r, c));
		putchar('\n');
	}
}
