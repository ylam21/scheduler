#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/month.h"

int check_error(void);
void solve(int matrix[ROWS][COLS]);
void print_matrix(int matrix[ROWS][COLS]);
void print_stats(int matrix[ROWS][COLS]);

int main(void) {
	srand(time(NULL)); //seed randomness
	if (check_error())
		return 0;
	int matrix[ROWS][COLS] = {0}; //init matrix;
	solve(matrix);
	print_matrix(matrix);
	print_stats(matrix);
	return 0;
}
