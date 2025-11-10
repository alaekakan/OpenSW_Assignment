CC = gcc

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib
INC_DIR = include

CFLAGS = -Wall -I$(INC_DIR) -fPIC
LDFLAGS_SHARED = -shared -Wl,-soname,libmyops.so.1
LDFLAGS_APP = -L$(LIB_DIR) -lmyops -Wl,-rpath=./lib -lm

LIB_SRCS = $(filter-out $(SRC_DIR)/myapp.c, $(wildcard $(SRC_DIR)/my*.c))
LIB_OBJS = $(LIB_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

APP_SRC = $(SRC_DIR)/myapp.c
APP_OBJ = $(APP_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

APP_TARGET = $(BIN_DIR)/myapp
LIB_TARGET = $(LIB_DIR)/libmyops.so.1.0

RM = rm -f
MKDIR_P = mkdir -p
LN_SF = ln -sf

.PHONY: all clean

all: $(APP_TARGET)

$(APP_TARGET): $(APP_OBJ) $(LIB_DIR)/libmyops.so
	$(MKDIR_P) $(BIN_DIR)
	$(CC) $(APP_OBJ) -o $@ $(LDFLAGS_APP)

$(LIB_DIR)/libmyops.so: $(LIB_TARGET)
	$(LN_SF) libmyops.so.1.0 $(LIB_DIR)/libmyops.so.1
	$(LN_SF) libmyops.so.1 $(LIB_DIR)/libmyops.so

$(LIB_TARGET): $(LIB_OBJS)
	$(MKDIR_P) $(LIB_DIR)
	$(CC) $(LDFLAGS_SHARED) -o $@ $(LIB_OBJS)

$(APP_OBJ): $(APP_SRC) $(INC_DIR)/myops.h
	$(MKDIR_P) $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/myops.h
	$(MKDIR_P) $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)/*.o
	$(RM) $(LIB_DIR)/*
	$(RM) $(APP_TARGET)