#include "config.h"

int is_in_conflict(user *worker) {
	int i = 1;
	while (i < 31) {
		if (worker->avail[i] == worker->not_avail[i] && worker->avail[i] != 0)
			return 1;
		i++;
	}
	return 0;
}

int input_isnt_ok(int row, int col) {
	if (row < 1 || col < 1)
		return 1;
	return 0;
}

int limit_isnt_ok(int row,int col,int num_user, int limit) {
	int bound = (row * col) / num_user;
	if (limit < bound)
		return 1;
	return 0;
}

int check_error(void) {
	if (limit_isnt_ok(ROWS,COLS,NUM_USERS,LIMIT))
		return 1;
	if (input_isnt_ok(ROWS,COLS))
		return 2;
	int i = 0;
	while (i < NUM_USERS) {
		if (is_in_conflict(users[i]))
			return 3;
		i++;
	}
	return 0;
}

