#ifndef USER_H
#define USER_H

#define DEPTH 1 // number of acceptable amount of days person can work in a row.

typedef struct {
	int id;
	char *name;
	int avail[31];
	int limits[3];
} user;

extern user user0;
extern user user1;
extern user user2;
extern user user3;
extern user user4;
extern user user5;
extern user user6;
extern user user7;
extern user user8;
extern user user9;
extern user *users[];
#define NUM_USERS 10

#endif
