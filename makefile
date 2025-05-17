CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRC = $(wildcard src/*.c) config/users.c
OBJ_DIR = build
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
BIN = bin

all: $(BIN)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN): $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


run: clean $(BIN)
	./$(BIN)

clean:
	rm -rf $(OBJ)

.PHONY = all clean
