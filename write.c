#include <unistd.h>
#include "config.h"

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

void write_sol(int matrix[ROWS][COLS]) {
	int i = 0;
	int j;
	char tmp;
	while (i < ROWS) {
		j = 0;
		write_day(i);
		while (j < COLS) {
			tmp = matrix[i][j] + '0';
			write(1,&tmp,1);
			if (j < COLS - 1)
				write(1," ",1);
			j++;
		}
		write(1,"\n",1);
		i++;
	}
	return;
}
