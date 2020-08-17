#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"
/**
 *print_grid - fn
 *@grid: tab
 *Return: void
 */
static void print_grid(int grid[3][3])
{
int i, j;
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
 *check - check fn
 *@grid1: tab
 *Return: int
 */
int check(int grid1[3][3])
{
int i, j;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid1[i][j] > 3)
return (0);
}
}
return (1);
}
/**
 *copy - fn
 *@p: tab
 *@s: tab
 *Return: void
 */
void copy(int p[3][3], int s[3][3])
{
int i, j;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
s[i][j] = p[i][j];
}
}
}
/**
 *sandpiles_sum - fn
 *@grid1: tab
 *@grid2: tab
 *Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
int s[3][3], p[3][3];
int i, j;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
s[i][j] = grid1[i][j] + grid2[i][j];
}
copy(s, p);
while (check(p) == 0)
{
copy(p, s);
printf("=\n");
print_grid(s);
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (s[i][j] > 3)
{
p[i][j] = p[i][j] - 4;
if (i + 1 < 3)
p[i + 1][j] = p[i + 1][j] + 1;
if (i - 1 > -1)
p[i - 1][j] = p[i - 1][j] + 1;
if (j + 1 < 3)
p[i][j + 1] = p[i][j + 1] + 1;
if (j - 1 > -1)
p[i][j - 1] = p[i][j - 1] + 1;
}
}
}
}
copy(p, grid1);
}
