#include <stdio.h>
#include <unistd.h>

#define ROWS 4
#define COLS 4
#define TOTAL 10
//TODO: handle TOTAL > 10

void write_sol(int matrix[ROWS][COLS]) {
	int i = 0;
	int j;
	char tmp;
	while (i < ROWS) {
		j = 0;
		while (j < COLS) {
			tmp = matrix[i][j] + '0';
			write(1,&tmp,1);
			if (j < COLS - 1)
				write(1," ",1);
			j++;
		}
		write(1,"\n",1);
		i++;
	}
	return;
}

int is_dupl(int matrix[ROWS][COLS], int row, int col, int n) {
	int i = 0;
	while (i < col) {
		if (n == matrix[row][i])
			return 1;
		i++;
	}
	return 0;
}

int count_num(int matrix[ROWS][COLS],int row, int col, int n) {
	int i = 0;
	int j;
	int count = 0;
	while (i <= row) {
		j = 0;
		while (j < COLS) {
			if (n == matrix[i][j])
			count++;
			if (i == row && j == col)
				return count;
			j++;
		}
		i++;
	}
}


int is_ok(int matrix[ROWS][COLS],int row, int col) {
	int last = matrix[row][col];
	//check if avail
	int limit = 1;
	if (is_dupl(matrix,row,col,last))
		return 0;
	if (count_num(matrix, row, col, last) > limit)
		return 0;
	return 1;
}

int solve(int matrix[ROWS][COLS],int row, int col) {
	if (row == ROWS)
		return 1;
	int i = 0;
	while (i < TOTAL) {
		matrix[row][col] = i;
		if (is_ok(matrix, row, col)) {
			if (solve(matrix,row + (col == COLS - 1),(col + 1) % COLS))
				return 1;
		}
		else
			i++;
	}
	return 0;
}

int main(void) {
	int matrix[ROWS][COLS] = {0};
	if (solve(matrix,0,0))
		write_sol(matrix);
	else
		printf("No solution");
	return 0;
}
