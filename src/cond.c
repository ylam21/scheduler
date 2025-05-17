#include <stdio.h>
#include "../include/month.h"
#include "../include/user.h"

int is_in_row(int matrix[ROWS][COLS], int row, int user_id) {
	for (int i=0;i<COLS;i++) {
		if (matrix[row][i] == user_id)
			return 1;
	}
	return 0;
}

int would_be_overworked(int matrix[ROWS][COLS], int row, int user_id, int depth) {
	int streak = 0;
	for (int i=1;i<=depth;i++) {
		if (is_in_row(matrix,row - i,user_id)) {
			streak++;
			if (streak >= depth)
				return 1;
		}
		else
			streak = 0;
	}
	return 0;
}

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
	int count = count_num(matrix,row,col,user_id) + 1; // '+1' as the user_id was chosen
	int target_min = users[user_id]->limits[0];
	int target_max = users[user_id]->limits[1];
	int target_exact = users[user_id]->limits[2];

	if (row == ROWS - 1 && col == COLS - 1) {
		if ((count < target_min) && (target_min != -1)) // Check for MIN
			return 1;
	}
	if (count > target_max && target_max != -1) // Check for MAX
		return 1;
	if (count > target_exact && target_exact != -1) // Check for EXACT
		return 1;
	return 0;
}

int chosen_id_isnt_ok(int matrix[ROWS][COLS],int row, int col, int user_id) {
	if (is_dupl(matrix,row,col,user_id))
		return 1;
	if (check_limits(matrix,row,col,user_id))
		return 1;
	if (would_be_overworked(matrix,row,user_id,DEPTH))
		return 1;
	return 0;
}
