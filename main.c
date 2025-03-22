#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"

int solve(int matrix[ROWS][COLS],int row, int col);
void write_sol(int matrix[ROWS][COLS]);
int check_error(void);

int get_longest(void);

int main(void) {
	srand(time(NULL)); //seed randomness
	printf("longest: %d\n",get_longest());
	if (check_error())
		return printf("Wrong input");
	int matrix[ROWS][COLS] = {0};
	if (solve(matrix,0,0))
		write_sol(matrix);
	else
		printf("No solution");
	//TODO: do own MACROS for error messages
	return 0;
}
