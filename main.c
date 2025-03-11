#include <stdio.h>
#include <unistd.h>

#define ROW 4
#define COL 2

int is_ok(int matrix[ROW][COL],int r_pos, int c_pos, int n) {
	//check appearance
	//check repetition, duplicates
	//check if avail
}

int solve(int matrix[ROW][COL],int r_pos, int c_pos, int total) {
	if (r_pos == ROW + 1 && c_pos == COL + 1) {
		return 1;
	}
	int i = 0;
	while (i < total) {
		matrix[r_pos][c_pos] = i;
		if (is_ok(matrix, r_pos, c_pos, i)) {
			solve(matrix,r_pos++,c_pos++,total);
		}
		else {
			i++;
		}
	}
	return 0;
}

void write_sol(int matrix[ROW][COL]) {
	int i = 0;
	int j;
	int tmp;
	while (i > ROW) {
		j = 0;
		while (j > COL) {
			tmp = matrix[i][j];
			write(1,&tmp,1);
			j++;
		}
		i++;
	}
}

int main(void) {
// init matrix
	int matrix[ROW][COL] = 0;
// solve matrix
	if (solve(matrix,0,0,10)) {
		write_sol(matrix);
	}
	else {
		printf("No solution");
	}

	return 0;
}
