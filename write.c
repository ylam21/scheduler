#include <unistd.h>
#include "config.h"

void write_sol(int matrix[ROWS][COLS]) {
	int i = 0;
	int j;
	char tmp;
	while (i < ROWS) {
		j = 0;
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
