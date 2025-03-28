#include "config.h"

int input_isnt_ok(int row, int col) {
	if (row < 1 || col < 1)
		return 1;
	return 0;
}

int check_error(void) {
	if (input_isnt_ok(ROWS,COLS))
		return 1;
	return 0;
}

