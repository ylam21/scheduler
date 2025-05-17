#include <stdio.h>
#include "../include/user.h"
#include "../include/month.h"

int get_id_count(int user_id, int matrix[ROWS][COLS]) {
	int count = 0;
	for (int i=0;i<ROWS;i++) {
		for (int j=0;j<COLS;j++) {
			if (user_id == matrix[i][j])
				count++;
		}
	}
	return count;
}

int fn_strlen(char *str) {
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

char *get_user_name(int user_id) {
	if (user_id == -1)
			return ("EMPTY");
	for (int i=0;i<NUM_USERS;i++) {
		if (user_id == users[i]->id)
			return users[i]->name;
	}
	return 0;
}

int get_user_max(int user_id) {
	int max = 0;
	for (int i=0;i<NUM_USERS;i++) {
		if (user_id == -1)
			return 0;
		if (user_id == users[i]->id) {
			for (int j=0;j<ROWS;j++) {
				if (users[i]->avail[j] != 0)
					max++;
			}
		}
	}
	return max;
}
