CC = gcc
AR = ar

SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin
INC_DIR = include

CFLAGS = -I$(INC_DIR) -Wall -c
LDFLAGS = -L$(LIB_DIR) -lmybasic

BASIC_OBJS = $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o
APP_OBJ = $(OBJ_DIR)/myapp.o
TARGET = $(BIN_DIR)/myapp
STATIC_LIB = $(LIB_DIR)/libmybasic.a

all: $(TARGET)
basic: $(STATIC_LIB)

$(TARGET): $(APP_OBJ) $(STATIC_LIB)
	@mkdir -p $(BIN_DIR)
	$(CC) $(APP_OBJ) -o $(TARGET) $(LDFLAGS)

$(STATIC_LIB): $(BASIC_OBJS)
	@mkdir -p $(LIB_DIR)
	$(AR) rcs $@ $^

$(APP_OBJ): $(SRC_DIR)/myapp.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(LIB_DIR)/*.a $(BIN_DIR)/$(TARGET)

.PHONY: all basic clean
