#include <stdio.h>
#include "config.h"

int solve(int matrix[ROWS][COLS],int row, int col);
void write_sol(int matrix[ROWS][COLS]);

int main(void) {
	int matrix[ROWS][COLS] = {0};
	if (solve(matrix,0,0))
		write_sol(matrix);
	else
		printf("No solution");
	//TODO: do own MACROS for error messages
	return 0;
}
