#include <stdio.h>
#include "../include/user.h"
#include "../include/month.h"

// Utility functions
char *get_user_name(int user_id);
int get_user_max(int user_id);
int get_id_count(int user_id, int matrix[ROWS][COLS]);

void print_stats(int matrix[ROWS][COLS]) {
	printf("\nStatistics:\n");
	char *name;
	int count, user_max;
	float fraction;
	float fract_aggr = 0;
	for (int id=-1;id<NUM_USERS;id++) {
		name = get_user_name(id);
		count = get_id_count(id,matrix);
		user_max = get_user_max(id);
		if (id == -1)
			printf("%s: %d\n",name,count);
		else if (user_max == 0) {
			fraction = 100;
			printf("%s: %d (inactive)\n", name, count);
		}
		else {
			fraction = (float)count/(float)user_max*100;
			printf("%s: %d/%d (%.0f %%)\n",name,count,user_max,fraction);
		}
		fract_aggr += fraction;
	}
	printf("Average: %.0f %%\n",fract_aggr/(float)NUM_USERS);
}
