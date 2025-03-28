#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"

int check_error(void);
void solve(int matrix[ROWS][COLS]);
void write_sol(int matrix[ROWS][COLS]);

int main(void) {
	srand(time(NULL));

	if (check_error()) {
		printf("Wrong input");
		return 1;
	}
	int matrix[ROWS][COLS] = {0};
	solve(matrix);
	write_sol(matrix);
	return 0;
}
