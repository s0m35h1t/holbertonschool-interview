#include "slide_line.h"

/**
 * slide_line - function that slides and merges an array of integer
 * @line: array of ints containing size elements, that must be slidued & merged
 * @size: size elements
 * @direction: can be either SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t pos_1 = 0, pos_2 = 1;
	size_t tmp1, tmp2, old, flag = 0;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		pos_1 = size - 1;
		pos_2 = size - 2;
	}

	for (tmp1 = 0; tmp1 < size; tmp1++)
	{
		old = pos_2;
		flag = 0;
		for (tmp2 = tmp1 + 1; tmp2 < size; tmp2++)
		{
			if (line[pos_1] != 0)
			{
				if (line[pos_2] == line[pos_1])
				{
					line[pos_1] = line[pos_1] * 2;
					line[pos_2] = 0;
					break;
				}
			}

			if (line[pos_1] == 0 && line[pos_2] != 0)
			{
				line[pos_1] = line[pos_2];
				line[pos_2] = 0;
				flag = 1;
				pos_2 = old;
				tmp1--;
				break;
			}

			if (line[pos_2] != 0)
				break;

			direction == SLIDE_LEFT ? pos_2++ : pos_2--;
		}
		if (line[pos_1] == 0)
			break;

		if (flag == 0)
		{
			if (direction == SLIDE_LEFT)
			{
				pos_1++;
				pos_2 = pos_1 + 1;
			}
			else if (direction == SLIDE_RIGHT)
			{
				pos_1--;
				pos_2 = pos_1 - 1;
			}
		}
	}
	return (1);
}
