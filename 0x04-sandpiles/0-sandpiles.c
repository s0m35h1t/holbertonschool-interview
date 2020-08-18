#include "sandpiles.h"



/**
* print_grid - Prints a grid.
* @grid: Grid to print
*/
void print_grid(int grid[3][3])
{
    int i, j;

    putchar("=");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}


/**
* sandpiles_sum - Sum two sandpiles.
* @grid1: First sandpile.
* @grid2: Second sandpile.
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j, us;
	int temp[3][3];

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];
    do
    {
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                temp[i][j] = grid1[i][j];
        us = 0;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (temp[i][j] > 3)
                {
                    if (!us)
                        print_g(grid1);
                    us = 1;
                    grid1[i][j] -= 4;
                    if (i > 0)
                        grid1[i - 1][j] += 1;
                    if (i < 2)
                        grid1[i + 1][j] += 1;
                    if (j > 0)
                        grid1[i][j - 1] += 1;
                    if (j < 2)
                        grid1[i][j + 1] += 1;
                }
            }
        }
    } while (us);
}
