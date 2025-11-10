CC = gcc
AR = ar
INC_DIR = ../include
LIB_DIR = ../lib
OBJ_DIR = obj
SRC_DIR = src

CFLAGS = -I$(INC_DIR) -Wall -c

OBJS = $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o
TARGET_LIB = $(LIB_DIR)/libmybasic.a

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	@mkdir -p $(LIB_DIR) # lib 디렉터리 생성 (루트 기준)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) # obj 디렉터리 생성 (자신 기준)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET_LIB)

.PHONY: all clean