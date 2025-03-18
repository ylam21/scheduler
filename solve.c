#include "config.h"

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
	return count;
}

int get_pos(int row, int col) {
	int mod_row = row + 1;
	int mod_col = col + 1;
	return ((mod_row * COLS) - (COLS - mod_col));
}

int isnt_avail(int row, int col, int user_id) {
	int pos = get_pos(row,col);
	int i = 0;
	while (i < 31) {
		if (users[user_id]->not_avail[i]==pos)
			return 1;
		i++;
	}
	return 0;
}

int is_ok(int matrix[ROWS][COLS],int row, int col) {
	int last = matrix[row][col];
	int limit = 8;
	//TODO: check right limit input
	//TODO: check individual limit
	if (isnt_avail(row,col,last))
		return 0;
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
