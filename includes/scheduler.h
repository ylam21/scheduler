#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>


#define ROWS 28 // number of days in a month: 28, 30, 31
#define COLS 2 // number of workers for a specific day
#define WORKER_COUNT 10
#define DEPTH 1

typedef struct s_worker {
	int id;
	char *name;
	int avail[31];
	int limits[3];
} t_worker;

int input_checker(t_worker workers[WORKER_COUNT]);
void solve(t_worker workers[WORKER_COUNT], int matrix[ROWS][COLS]);
void print_stats(t_worker workers[WORKER_COUNT], int matrix[ROWS][COLS]);
void print_matrix(t_worker workers[WORKER_COUNT], int matrix[ROWS][COLS]);
int chosen_id_isnt_ok(t_worker workers[WORKER_COUNT],int matrix[ROWS][COLS],int row, int col, int worker_id);

#include "utils.h"
#include "errors.h"

#endif
