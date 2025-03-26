#include "config.h"
#include <stdio.h>
#include <stdlib.h>

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
	return (((row + 1) * COLS) - (COLS - (col + 1))) - 1;
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

int is_ok(int matrix[ROWS][COLS],int row, int col) {
	int last_id = matrix[row][col];
	//TODO: check individual limit
	//TODO: fill cell with "EMPTY" str if nobody can work
	if (is_dupl(matrix,row,col,last_id))
		return 0;
	if (count_num(matrix, row, col, last_id) > LIMIT)
		return 0;
	return 1;
}

// int solve(int matrix[ROWS][COLS],int row, int col) {
// 	if (row == ROWS)
// 		return 1;
// 	while (1) {
// 		matrix[row][col] = get_random_user();
// 		if (is_ok(matrix, row, col)) {
// 			if (solve(matrix,row + (col == COLS - 1),(col + 1) % COLS))
// 				return 1;
// 		}
// 	}
// 	return 0;
// }

int *get_match(int row, int col, int match, int *size_out) {
	if (!size_out) return NULL;

	int *arr = (int *)malloc(sizeof(int) * NUM_USERS);
	if (!arr) {
		printf("Allocation failed\n");
		return NULL;
	}

	int count = 0;
	for (int i = 0; i < NUM_USERS; i++) {
		if (users[i]->avail[get_pos(row,col)] == match)
			arr[count++] = users[i]->id;
	}

	if (!count) {
		free(arr);
		*size_out = count;
		return NULL;
	}

	int *resized = (int *)realloc(arr,sizeof(int) * count);
	if (!resized) {
		printf("Allocation failed\n");
		*size_out = count;
		return arr;
	}

	*size_out = count;
	return resized;
}

int *remake_array(int *arr, int remove, int *size) {
	for (int i = 0; i < *size; i++) {
		if (arr[i] == remove) {
			while (i < *size - 1) {
				arr[i] = arr[i + 1];
				i++;
			}
			break;
		}
	}
	*size = size - 1;
	int *resized = (int *)realloc(arr,sizeof(int) * (*size - 1));
	if (!resized) {
		printf("Allocation failed\n");
		return arr;
	}
	return resized;
}

int assign_user(int matrix[ROWS][COLS], int row, int col) {
	int chosen = 0;

	int size;
	int *prior_users = get_match(row,col,2,&size);
	if (size) {
		while (size) {
			chosen = prior_users[rand() % size];
			if (is_dupl(matrix,row,col,chosen)) {
				remake_array(prior_users,chosen,&size);
			}
		}

	}

	int *avail_users = get_match(row,col,1,&size);


	return chosen;
}

int solve(int matrix[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; i < COLS; j++) {
			matrix[i][j] = assign_user(matrix, i, j);
		}
	}
}
