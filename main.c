#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"

int solve(int matrix[ROWS][COLS],int row, int col);
void write_sol(int matrix[ROWS][COLS]);
int check_error(void);

int main(void) {
	srand(time(NULL));
	if (check_error())
		return printf("Wrong input");
	int matrix[ROWS][COLS] = {0};
	if (solve(matrix,0,0))
		write_sol(matrix);
	else
		printf("No solution");
	return 0;
}
