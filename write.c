#include <unistd.h>
#include "config.h"

int get_len(char *str) {
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

int get_longest(void) {
	int i = 0;
	int longest = get_len(users[0]->name);
	int curr;
	while (users[i]) {
		curr = get_len(users[i]->name);
		if (curr > longest)
			longest = curr;
		i++;
	}
	return longest;
}

void write_space(int nb) {
	int i = 0;
	while (i < nb) {
		write(1," ",1);
		i++;
	}
	return;
}

void write_name(char *str) {
	int i = 0;
	while (str[i]) {
		write(1,&str[i],1);
		i++;
	}
	int num_space = get_longest() - get_len(str);
	i = 0;
	while (i < num_space) {
		write(1," ",1);
		i++;
	}
	return;
}

void write_num(int num) {
	char tmp;
	tmp = (num / 10) + '0';
	write(1,&tmp,1);
	tmp = (num % 10) + '0';
	write(1,&tmp,1);
	return;
}

void write_day(int day) {
	write(1,"Day ",4);
	write_num(day + 1);
	write(1,": ",2);
	return;
}

char *get_name(int nb) {
	char *empty = "EMPTY";
	if (nb == 0)
		return empty;

	for (int i = 0;i<NUM_USERS;i++) {
		if (users[i]->id == nb) {
			return users[i]->name;
		}
	}

	return 0;
}

void write_sol(int matrix[ROWS][COLS]) {
		int i = 0;
		int j;
		while (i < ROWS) {
			j = 0;
			write_day(i);
			while (j < COLS) {
				write_name(get_name(matrix[i][j]));
				if (j < COLS - 1)
					write(1," ",1);
				j++;
			}
			write(1,"\n",1);
			i++;
		}
		return;
	}
