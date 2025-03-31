#include "config.h"
#include <stdio.h>

int count_num(int matrix[ROWS][COLS], int row, int col, int user_id) {
	int i = 0;
	int j;
	int count = 0;
	while (i <= row) {
		j = 0;
		while (j < COLS) {
			if (user_id == matrix[i][j])
				count++;
			if (i == row && j == col)
				return count;
			j++;
		}
		i++;
	}
	return count;
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

int check_limits(int matrix[ROWS][COLS],int row, int col, int user_id) {
	int count = count_num(matrix,row,col,user_id) + 1;
	int target_min = users[user_id - 1]->limits[0];
	int target_max = users[user_id - 1]->limits[1];
	int target_exact = users[user_id - 1]->limits[2];

	if (row == ROWS - 1 && col == COLS - 1) {
		if ((count < target_min) && (target_min != -1)) //check MIN
			return 1;
	}
	if (count > target_max && target_max != -1) //check MAX
		return 1;
	if (count > target_exact && target_exact != -1) //check EXACT
		return 1;
	return 0;
}

int chosen_isnt_ok(int matrix[ROWS][COLS],int row, int col, int user_id) {
	if (is_dupl(matrix,row,col,user_id))
		return 1;
	if (check_limits(matrix,row,col,user_id))
		return 1;
	return 0;
}
