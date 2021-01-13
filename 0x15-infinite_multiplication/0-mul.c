#include <stdlib.h>
#include <unistd.h>

/**
 * multiply - multiply two strings of digits
 * @num1: first number
 * @num2: second number
 * @l1: first number length
 * @l2: second number length
 * Return: 98 on error or 0 on success
 */
int multiply(char num1[], char num2[], long int l1, long int l2)
{
	long int i, j, r;
	int carry;
	char *result, *beg;

	result = malloc(l1 + l2 + 1);
	if (result == NULL)
	{
		write(1, "Error\n", 6);
		return (98);
	}
	for (i = 0; i < l1 + l2 + 3; i++)
		result[i] = 0;
	for (i = l1 - 1; i >= 0; i--)
		for (j = l2 - 1; j >= 0; j--)
		{
			result[i + j + 1] += ((num1[i] - '0') *
								  (num2[j] - '0'));
			for (r = i + j + 1; result[r] > 9;
				 r--)
			{
				carry = result[r] / 10;
				result[r - 1] += carry;
				result[r] %= 10;
			}
		}
	for (i = l1 + l2 - 1; i >= 0; i--)
		result[i] += '0';
	for (beg = result; *beg == '0' && beg[1] != 0; beg++)
		l1--;
	l1 += l2;
	write(1, beg, l1);
	write(1, "\n", 1);
	free(result);
	return (0);
}

/**
 * main -  multiplies two positive numbers
 * @argc: number of arguments
 * @argv: arguments list
 * Return: 98 if error, 0 if success
 */
int main(int argc, char *argv[])
{
	char *i, *j;
	long int l1, l2;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (98);
	}
	l1 = 0;
	for (i = argv[1]; *i != 0; i++, l1++)
		if (*i < '0' || *i > '9')
		{
			write(1, "Error\n", 6);
			return (98);
		}
	l2 = 0;
	for (j = argv[2]; *j != 0; j++, l2++)
		if (*j < '0' || *j > '9')
		{
			write(1, "Error\n", 6);
			return (98);
		}
	if (l1 == 0 || l2 == 0)
	{
		write(1, "Error\n", 6);
		return (98);
	}
	for (i = argv[1]; *i == '0' && i[1] != 0; l1--)
		i++;
	for (j = argv[2]; *j == '0' && j[1] != 0; l2--)
		j++;
	return (multiply(i, j, l1, l2));
}
