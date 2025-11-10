CC = gcc
AR = ar
INC_DIR = ../include
LIB_DIR = ../lib
OBJ_DIR = obj
SRC_DIR = src

CFLAGS = -I$(INC_DIR) -Wall -c

OBJS = $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o
TARGET_LIB = $(LIB_DIR)/libmyadvanced.a

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	@mkdir -p $(LIB_DIR)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET_LIB)

.PHONY: all clean