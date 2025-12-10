#include "../includes/scheduler.h"

void print_stats(t_worker workers[WORKER_COUNT], int matrix[ROWS][COLS])
{
	printf("\nStatistics:\n");
	char *name;
	int count, user_max;
	float fraction;
	float fract_aggr = 0;
	for (int id=-1;id<WORKER_COUNT;id++) {
		name = get_worker_name(workers, id);
		count = get_id_count(id,matrix);
		user_max = get_worker_max(workers, id);
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
	printf("Average: %.0f %%\n",fract_aggr/(float)WORKER_COUNT);
}
