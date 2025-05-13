#include <stdio.h>
#include "../include/user.h"
#include "../include/month.h"

// Utility functions
char *get_user_name(int user_id);
int get_user_max(int user_id);

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

void print_stats(int matrix[ROWS][COLS]) {
	char *name;
	int count, user_max;
	float fraction;
	float fract_aggr = 0;
	printf("\nStatistics:\n");
	for (int id=0;id<NUM_USERS;id++) {
		name = get_user_name(id);
		count = get_id_count(id,matrix);
		user_max = get_user_max(id);
		if (user_max == 0)
			fraction = 100;
		else
			fraction = (float)count/(float)user_max*100;
		if (id == 0)
			printf("%s: %d\n",name,count);
		else {
			fract_aggr += fraction;
			printf("%s: %d/%d (%.0f %%)\n",name,count,user_max,fraction);
		}
	}
	printf("Average: %.0f %%\n",fract_aggr/(float)NUM_USERS);
}
