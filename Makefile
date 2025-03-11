CFLAGS = -Wall -Wextra -Werror

main.o: main.c
	gcc $(CFLAGS) -c main.c
