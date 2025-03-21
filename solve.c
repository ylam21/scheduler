#include "config.h"
#include <stdio.h>

int get_random_user(void);

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
	return (((row + 1) * COLS) - (COLS - (col + 1)));
}

int check_avail(int row, int col, int user_id) {
	if (users[user_id]->avail[0]==0)
		return 0;
	int pos = get_pos(row,col);
	int i = 0;
	while (i < 31) {
		if (users[user_id]->avail[i]==pos)
			return 0;
		i++;
	}
	return 1;
}

int check_not_avail(int row, int col, int user_id) {
	if (users[user_id]->not_avail[0]==0)
		return 0;
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
	int last_id = matrix[row][col];
	//TODO: check individual limit
	//TODO: fill cell with "EMPTY" str if nobody can work
	if (check_avail(row,col,last_id))
		return 0;
	if (check_not_avail(row,col,last_id))
		return 0;
	if (is_dupl(matrix,row,col,last_id))
		return 0;
	if (count_num(matrix, row, col, last_id) > LIMIT)
		return 0;
	return 1;
}

int solve(int matrix[ROWS][COLS],int row, int col) {
	if (row == ROWS)
		return 1;
	while (1) {
		matrix[row][col] = get_random_user();
		if (is_ok(matrix, row, col)) {
			if (solve(matrix,row + (col == COLS - 1),(col + 1) % COLS))
				return 1;
		}
	}
	return 0;
}
