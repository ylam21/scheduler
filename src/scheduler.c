#include "../includes/scheduler.h"

t_worker worker0 = {0,"Dasa",    {0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1    }, {-1,-1,-1}};
t_worker worker1 = {1,"Katerina",{0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1    }, {-1,-1,-1}};
t_worker worker2 = {2,"Nada",    {1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1    }, {-1,-1,-1}};
t_worker worker3 = {3,"Baubek",  {1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1    }, {-1,-1,-1}};
t_worker worker4 = {4,"Samuel",  {1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1    }, {-1,-1,-1}};
t_worker worker5 = {5,"Lucie",   {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0    }, {-1,-1,-1}};
t_worker worker6 = {6,"Maruska", {1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1    }, {-1,-1,-1}};
t_worker worker7 = {7,"Zaneta",  {0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0    }, {-1,-1,-1}};
t_worker worker8 = {8,"Ondrej",  {1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1    }, {-1,-1,-1}};
t_worker worker9 = {9,"Matej",   {1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1    }, {-1,-1,-1}};

void load_workers(t_worker workers[WORKER_COUNT])
{
	workers[0] = worker0;
	workers[1] = worker1;
	workers[2] = worker2;
	workers[3] = worker3;
	workers[4] = worker4;
	workers[5] = worker5;
	workers[6] = worker6;
	workers[7] = worker7;
	workers[8] = worker8;
	workers[9] = worker9;
}

void matrix_init(int matrix[ROWS][COLS])
{
	for (int i=0;i<ROWS;i++)
	{
		for (int j=0;j<COLS;j++)
		{
			matrix[i][j] = -1;
		}
	}
}

int main(void)
{
	t_worker workers[WORKER_COUNT];
	int matrix[ROWS][COLS];

	load_workers(workers);

	if (input_checker(workers) != 0)
	{
		return 1;
	}

	matrix_init(matrix);

	srand(time(NULL));
	solve(workers, matrix);

	print_matrix(workers, matrix);
	print_stats(workers, matrix);

	return 0;
}
