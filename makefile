
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iinclude

CFILES = src/cond.c src/error.c src/main.c src/solve.c src/write.c config/users.c
OBJECTS := src/cond.o src/error.o src/main.o src/solve.o src/write.o config/users.o

BINARY = bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) config/*.o src/*.o
