#include "config.h"
#include <stdio.h>
#include <stdlib.h>

int is_dupl(int matrix[ROWS][COLS], int row, int col, int n);

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
	// check if there is not better sol
	return (((row + 1) * COLS) - (COLS - (col + 1))) - 1;
}

int *get_match(int day, int match, int *size) {
	int *arr = malloc(sizeof(int) * NUM_USERS);
	if (!arr) {
		printf("Allocation failed 0\n");
		return NULL;
	}

	int count = 0;
	for (int i = 0; i < NUM_USERS; i++) {
		if (users[i]->avail[day] == match)
			arr[count++] = users[i]->id;
	}

	if (!count) {
		free(arr);
		*size = 0;
		return NULL;
	}

	int *resized = realloc(arr,sizeof(int) * count);
	if (!resized) {
		printf("Reallocation failed 1\n");
		*size = count;
		return arr;
	}
	*size = count;
	return resized;
}

int *remove_int(int *arr, int remove, int *size) {
	for (int i = 0; i < (*size); i++) {
		if (arr[i] == remove) {
			while (i < (*size) - 1) {
				arr[i] = arr[i + 1];
				i++;
			}
			(*size)--;

			if (*size == 0) {
				free(arr);
				return NULL;
			}

			int *resized = realloc(arr,sizeof(int) * (*size));
			if (!resized) {
				printf("Allocation failed 2\n");
				return arr;
			}
			return resized;
		}
	}
	return arr;
}

int assign_user(int matrix[ROWS][COLS], int row, int col) {
	int chosen = 0;
	int size = 0;
	int *arr;

	arr = get_match(row,2,&size); //assign priority first
	while (size > 0) {
		chosen = arr[rand() % size];
		if (is_dupl(matrix,row,col,chosen)) {
			arr = remove_int(arr,chosen,&size);
			if (!arr)
				break;
		}
		else {
			free(arr);
			return chosen;
		}
	}
	free(arr);

	arr = get_match(row,1,&size); //assign avail users if there is no prior. users
	while (size) {
		chosen = arr[rand() % size];
		if (is_dupl(matrix,row,col,chosen)) {
			arr = remove_int(arr,chosen,&size);
			if (!arr)
				break;
		}
		else {
			free(arr);
			return chosen;
		}
	}
	if (arr)
	free(arr);

	return 0; //no one can work;
}

void solve(int matrix[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			matrix[i][j] = assign_user(matrix, i, j);
		}
	}
	return;
}
