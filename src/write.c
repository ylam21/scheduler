#include <stdio.h>
#include <unistd.h>
#include "../include/month.h"
#include "../include/user.h"

// Utility functions
int fn_strlen(char *str);
char *get_user_name(int user_id);

int get_longest(void) {
	int i = 0;
	int longest = fn_strlen(users[0]->name);
	int curr;
	while (users[i]) {
		curr = fn_strlen(users[i]->name);
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
	int num_space = get_longest() - fn_strlen(str);
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

void print_matrix(int matrix[ROWS][COLS]) {
		int i = 0;
		int j;
		printf("\nResult:\n");
		while (i < ROWS) {
			j = 0;
			write_day(i);
			while (j < COLS) {
				write_name(get_user_name(matrix[i][j]));
				if (j < COLS - 1)
					write(1," ",1);
				j++;
			}
			write(1,"\n",1);
			i++;
		}
		return;
	}
