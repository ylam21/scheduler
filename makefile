
CC := gcc
CFLAGS := -Wall -Wextra -Werror
CFILES := main.c solve.c write.c users.c error.c cond.c
all: $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o a.out

clean:
	rm -f a.out
