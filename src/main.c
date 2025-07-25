#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/month.h"

int errors(void);
void solve(int matrix[ROWS][COLS]);
void print_matrix(int matrix[ROWS][COLS]);
void print_stats(int matrix[ROWS][COLS]);

int main(void) {
	srand(time(NULL)); //seed randomness
	if (errors())
		return 0;
	int matrix[ROWS][COLS];
	for (int i=0;i<ROWS;i++){
		for (int j=0;j<COLS;j++){
			matrix[i][j] = -1; //init matrix
		}
	}
	solve(matrix);
	print_matrix(matrix);
	print_stats(matrix);
	return 0;
}
