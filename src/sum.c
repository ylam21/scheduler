#include <stdio.h>
#include "../include/user.h"
#include "../include/month.h"

int get_id_count(int id, int matrix[ROWS][COLS]) {
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

int get_user_max(int id) {
	int max = 0;
	for (int i=0;i<NUM_USERS;i++) {
		if (id == 0)
			return 0;
		if (id == users[i]->id) {
			for (int j=0;j<ROWS;j++) {
				if (users[i]->avail[j] != 0)
					max++;
			}
		}
	}
	return max;
}

void print_sum(int matrix[ROWS][COLS]) {
	char *name;
	int count, user_max;
	float fraction;
	float fract_aggr = 0;
	printf("Count:\n");
	for (int i=0;i<NUM_USERS;i++) {
		name = get_name1(i);
		count = get_id_count(i,matrix);
		user_max = get_user_max(i);
		if (user_max == 0)
			fraction = 100;
		else
			fraction = (float)count/(float)user_max*100;
		if (i == 0)
			printf("%s: %d\n",name,count);
		else {
			fract_aggr += fraction;
			printf("%s: %d/%d (%.0f %%)\n",name,count,user_max,fraction);
		}
	}
	printf("Average: %.0f %%\n",fract_aggr/(float)NUM_USERS);
}
