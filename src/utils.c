#include "../includes/scheduler.h"

int get_id_count(int user_id, int matrix[ROWS][COLS])
{
	int count = 0;
	for (int i=0;i<ROWS;i++) {
		for (int j=0;j<COLS;j++) {
			if (user_id == matrix[i][j])
				count++;
		}
	}
	return count;
}

char *get_worker_name(t_worker workers[WORKER_COUNT], int user_id)
{
	if (user_id == -1)
			return ("EMPTY");
	for (int i=0; i < WORKER_COUNT;i++) {
		if (user_id == workers[i].id)
			return workers[i].name;
	}
	return 0;
}

int get_worker_max(t_worker workers[WORKER_COUNT], int user_id)
{
	int max = 0;
	for (int i=0;i < WORKER_COUNT;i++) {
		if (user_id == -1)
			return 0;
		if (user_id == workers[i].id) {
			for (int j=0;j<ROWS;j++) {
				if (workers[i].avail[j] != 0)
					max++;
			}
		}
	}
	return max;
}
