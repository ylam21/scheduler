#include <stdio.h>
#include <unistd.h>

#define ROWS 4
#define COLS 4
#define TOTAL 10

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


int is_ok(int matrix[ROWS][COLS],int row, int col, int num) {
	//check appearance
	//check repetition, duplicates DONE
	//check if avail
	return 1;
}

int solve(int matrix[ROWS][COLS],int row, int col, int total) {
	if (row == ROWS)
		return 1;
	int i = 0;
	while (i < total) {
		matrix[row][col] = i;
		if (is_ok(matrix, row, col, i)) {
			if (solve(matrix,row + (col == COLS - 1),(col + 1) % COLS,total))
				return 1;
		}
		else
			i++;
	}
	return 0;
}

int main(void) {
// init matrix
	int matrix[ROWS][COLS] = {0};
// solve matrix
	if (solve(matrix,0,0,TOTAL)) {
		write_sol(matrix);
	}
	else {
		printf("No solution");
	}

	return 0;
}
