CFLAGS := -Wall -Wextra -Werror
CFILES := main.c solve.c write.c users.c
all: $(CFILES)
	gcc $(CFLAGS) $(CFILES) -o a.out

clean:
	rm -f a.out
