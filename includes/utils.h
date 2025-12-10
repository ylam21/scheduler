#ifndef UTILS_H
#define UTILS_H

#include "scheduler.h"

int get_worker_max(t_worker workers[WORKER_COUNT], int user_id);
char *get_worker_name(t_worker workers[WORKER_COUNT], int user_id);
int get_id_count(int user_id, int matrix[ROWS][COLS]);

#endif
