#include <stdio.h>
#include "../include/user.h"
#include "../include/month.h"

int fn_strlen(char *str) {
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

char *get_user_name(int user_id) {
	if (user_id == 0)
			return ("EMPTY");
	for (int i=0;i<NUM_USERS;i++) {
		if (user_id == users[i]->id)
			return users[i]->name;
	}
	return 0;
}

int get_user_max(int user_id) {
	int max = 0;
	for (int i=0;i<NUM_USERS;i++) {
		if (user_id == 0)
			return 0;
		if (user_id == users[i]->id) {
			for (int j=0;j<ROWS;j++) {
				if (users[i]->avail[j] != 0)
					max++;
			}
		}
	}
	return max;
}
