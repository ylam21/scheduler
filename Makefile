# Project settings
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
NAME = $(BIN_DIR)/scheduler

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

RM = rm -rf

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

all: $(NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(NAME): $(OBJ) | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


run:
	./$(NAME)

clean:
	$(RM) $(BUILD_DIR)

.PHONY = all clean run
