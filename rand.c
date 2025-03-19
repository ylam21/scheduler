#include <stdlib.h>
#include "config.h"

int get_random_user(void) {
	return rand() % NUM_USERS;
}
