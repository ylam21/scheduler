
#ifndef CONFIG_H
#define CONFIG_H

#define ROWS 4
#define COLS 4
#define TOTAL 9
//TODO: handle error input of TOTAL
//TODO: handle TOTAL > 10

typedef struct {
	int id;
	char *name;
	int not_avail[31];
	int limit;
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
extern user *users[];
#endif
