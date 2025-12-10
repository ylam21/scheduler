#include "../includes/scheduler.h"

int check_id(int id)
{
	return (id < 0);
}

int check_name(char *name)
{
	if (!name)
	{
		return 1;
	}
	if (strlen(name) == 0)
	{
		return 2;
	}
	return 0;
}

int is_inrange(int i, int low, int high)
{
	return (low <= i && i <= high);
}

int check_avail(int arr[ROWS])
{
	for (int i = 0; i < ROWS; i++)
	{
		if (is_inrange(arr[i], 0, 3) != 1)
		{
			return 1;
		}
	}
	return 0;
}


int check_limits_2(int arr[3])
{
	for (int i = 0; i < 3; i++)
	{
		if (is_inrange(arr[i], -1, 2) != 1)
		{
			return 1;
		}
	}
	return 0;
}


int check_worker(t_worker w)
{
	if (check_id(w.id) != 0)
	{
		return 1;
	}
	if (check_name(w.name) != 0)
	{
		return 2;
	}
	if (check_avail(w.avail) != 0)
	{
		return 3;
	}
	if (check_limits_2(w.limits) != 0)
	{
		return 4;
	}
	return 0;
}

int input_checker(t_worker workers[WORKER_COUNT])
{
	if (WORKER_COUNT < 0)
	{
		print_error(ERR_WORKER_COUNT);
		return 1;
	}
	if (ROWS > 31 || 0 > ROWS)
	{
		print_error(ERR_ROWS);
		return 2;
	}
	if (COLS > 2 || 0 > COLS)
	{
		print_error(ERR_COLS);
		return 3;
	}
	for (int i = 0; i < WORKER_COUNT; i++)
	{
		if (check_worker(workers[i]) != 0)
		{
			return 4;
		}
	}
	return 0;
}
