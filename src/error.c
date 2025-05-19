#include "../include/month.h"
#include "../include/user.h"
#include <stdio.h>
int input_isnt_ok(int row, int col) {
	if (row < 1 || col < 1)
		return 1;
	return 0;
}

int check_config(void) {
	//check right input for scheduler/config/config.c
	for (int i=0;i<NUM_USERS;i++) {
		//check if int *avail has right input
		for (int j=0;j<ROWS;j++) {
			int day = users[i]->avail[j];
			if ((day != 0)&&(day != 1)&&(day != 2)) {
				printf("Error: user with id:%d has wrong input\n",users[i]->id);
				return 1;
			}

		}
	}
	return 0;
}

int errors(void) {
	if (input_isnt_ok(ROWS,COLS))
		return 1;
	if (check_config())
		return 1;
	return 0;
}

