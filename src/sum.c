#include <stdio.h>
#include <unistd.h>
#include "../include/user.h"
#include "../include/month.h"

int get_count(int id, int matrix[ROWS][COLS]) {
	int count = 0;
	for (int i=0;i<ROWS;i++) {
		for (int j=0;j<COLS;j++) {
			if (id == matrix[i][j])
				count++;
		}
	}
	return count;
}

char *get_name1(int id) {
	for (int i=0;i<NUM_USERS;i++) {
		if (id == 0)
			return ("EMPTY");
		if (id == users[i]->id)
			return users[i]->name;
	}
	return 0;
}

void print_sum(int matrix[ROWS][COLS]) {
	char *name;
	int count;
	write(1,"Count:\n",7);
	for (int i=0;i<NUM_USERS;i++) {
		name = get_name1(i);
		count = get_count(i,matrix);
		printf("%s: %d\n",name,count);
	}
}
