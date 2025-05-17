#include <stdio.h>
#include <stdlib.h>
#include "../include/month.h"
#include "../include/user.h"

// Utility functions
void print_array(int matrix[ROWS][COLS],int *arr, int size);
int get_id_count(int user_id, int matrix[ROWS][COLS]);
int get_user_max(int user_id);
int chosen_id_isnt_ok(int matrix[ROWS][COLS],int row, int col, int user_id);

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

int *fract_sort(int matrix[ROWS][COLS], int *arr,int size) {
	int tmp;
	float curr, next;
	// Bubble sort from lowest to highest
	for (int i=0;i<size-1;i++) {
		for (int j=0;j<size-1-i;j++) {
			 curr = (float)get_id_count(arr[j],matrix)/get_user_max(arr[j]); // "get_id_count" irritates thought whole matrix - not necessary
			 next = (float)get_id_count(arr[j+1],matrix)/get_user_max(arr[j+1]);
			 if (curr > next) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			 }
		}
	}
	return arr;
}

int get_poolsize(int matrix[ROWS][COLS], int *arr, int size) {
	// Compute pool_size of equally ranked users
	int pool_size = 1;
	float best =(float)get_id_count(arr[0],matrix)/get_user_max(arr[0]);
	for (int i=1;i<size;i++) {
		float f = (float)get_id_count(arr[i],matrix)/get_user_max(arr[i]);
		if (f == best)
			pool_size++;
		else
			break;
	}
	return pool_size;
}

int find_user(int matrix[ROWS][COLS],int row,int col,int match) {
	int size = 0;
	int chosen_id = -1; // if function return -1 nobody is chosen_id

	int *arr;
	arr = get_match(row,match,&size);

	if (!size)
		return chosen_id;

	arr = fract_sort(matrix,arr,size);

	if (!arr)
		return chosen_id;

	while (size > 0) {
		int pool_size = get_poolsize(matrix,arr,size);
		if (pool_size > 0)
			chosen_id = arr[rand() % pool_size];
		else {
			printf("Dividing by zero\n");
			return chosen_id;
		}
		if (chosen_id_isnt_ok(matrix,row,col,chosen_id)) {
			arr = remove_int(arr,chosen_id,&size);
			chosen_id = -1;
			if (!arr)
				break;
		}
		else {
			free(arr);
			return chosen_id;
		}
	}

	if (arr)
		free(arr);
		
	return chosen_id;
}

int assign_user(int matrix[ROWS][COLS], int row, int col) {
	int chosen_id;
		chosen_id = find_user(matrix,row,col,2); // Look if some user has priority (match = 2)
	if (chosen_id == -1)
		chosen_id = find_user(matrix,row,col,1); // If nobody has priority then look if somebody is available (match = 1)
	return chosen_id;
}

void solve(int matrix[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			matrix[i][j] = assign_user(matrix, i, j);
		}
	}
	return;
}
