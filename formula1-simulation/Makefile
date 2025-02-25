CC = gcc
CFLAGS = -Wall -Wextra -g3
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c) \
       $(wildcard $(SRC_DIR)/logger/*.c) \
       $(wildcard $(SRC_DIR)/data/*.c) \
       $(wildcard $(SRC_DIR)/race/*.c) \
       $(wildcard $(SRC_DIR)/weather/*.c) \
       $(wildcard $(SRC_DIR)/teams/*.c) \
       $(wildcard $(SRC_DIR)/drivers/*.c) \
       $(wildcard $(SRC_DIR)/simulation/*.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Create output directories
$(shell mkdir -p $(OBJ_DIR)/logger $(OBJ_DIR)/data $(OBJ_DIR)/race $(OBJ_DIR)/weather $(OBJ_DIR)/teams $(OBJ_DIR)/drivers $(OBJ_DIR)/simulation $(BIN_DIR))

# Main target
TARGET = $(BIN_DIR)/formula1_sim.exe

all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

.PHONY: all clean