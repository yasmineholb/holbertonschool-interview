#ifndef _sandp_
#define _sandp_
#include <stdlib.h>
#include <stdio.h>
static void print_grid(int grid[3][3]);
int check(int grid1[3][3]);
void copy(int p[3][3], int s[3][3]);
void print_grid_sum(int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
#endif
