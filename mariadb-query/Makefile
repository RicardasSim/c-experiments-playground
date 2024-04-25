CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow
DEBUG_FLAGS   = -O0 -DDEBUG -g
RELEASE_FLAGS = -O3 -DNDEBUG
# mysql_config --cflags
#INC_MYSQL=$(shell mysql_config --cflags)
# mysql_config --libs
#LIB_MYSQL=$(shell mysql_config --libs)
# mariadb_config --cflags
INC_MYSQL = $(shell mariadb_config --cflags)
# mariadb_config --libs
LIB_MYSQL = $(shell mariadb_config --libs)
OBJ = main.o
TARGET_PROGRAM = testprog

all: CFLAGS += $(RELEASE_FLAGS)
all: $(TARGET_PROGRAM)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET_PROGRAM)

$(TARGET_PROGRAM): $(OBJ)
	$(CC) -o $(TARGET_PROGRAM) $(OBJ) $(LIB_MYSQL)

main.o: main.c
	$(CC) $(CFLAGS) $(INC_MYSQL) -c main.c -o main.o

clean:
	@echo Cleaning up...
	@rm -f *.o
	@rm -f $(TARGET_PROGRAM)
	@echo Done.
