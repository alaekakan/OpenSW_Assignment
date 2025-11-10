CC = gcc

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include
LIB_DIR = lib

STATIC_LIBS = $(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a
LDFLAGS = -L$(LIB_DIR) -lmybasic -lmyadvanced -lm
CFLAGS = -I$(INC_DIR) -Wall -c

TARGET = $(BIN_DIR)/myapp

.PHONY: all basic_ops advanced_ops clean

all: basic_ops advanced_ops $(TARGET)

default: all

$(TARGET): $(SRC_DIR)/myapp.c $(STATIC_LIBS)
	@mkdir -p $(OBJ_DIR)
	# 1. myapp.c 컴파일
	$(CC) $(CFLAGS) $(SRC_DIR)/myapp.c -o $(OBJ_DIR)/myapp.o
	@mkdir -p $(BIN_DIR)
	# 2. myapp.o 링크
	$(CC) $(OBJ_DIR)/myapp.o -o $(TARGET) $(LDFLAGS)

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops:
	$(MAKE) -C advanced_ops

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)
	# 각 하위 디렉터리로 가서 'make clean'을 실행
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean
	# 루트의 lib도 정리
	rm -rf $(LIB_DIR)