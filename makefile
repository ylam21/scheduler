CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iinclude

SRC = $(wildcard src/*.c) config/users.c
OBJECTS := $(SRC:.c=.o)

BIN = print

all: $(BIN)

$(BIN): $(OBJECTS)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJECTS)
