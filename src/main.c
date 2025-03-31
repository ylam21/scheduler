#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "month.h"

int check_error(void);
void solve(int matrix[ROWS][COLS]);
void write_sol(int matrix[ROWS][COLS]);

int main(void) {
	srand(time(NULL)); //seed randomness
	if (check_error())
		return 0;
	int matrix[ROWS][COLS] = {0}; //init matrix;
	solve(matrix);
	write_sol(matrix);
	return 0;
}
