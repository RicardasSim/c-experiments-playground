CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow
DEBUG_FLAGS   = -O0 -DDEBUG -g
RELEASE_FLAGS = -O3 -DNDEBUG
INC_LUA = $(shell pkg-config --cflags lua)
LIB_LUA = $(shell pkg-config --libs lua)
OBJ = main.o
TARGET_PROGRAM = testprog

all: CFLAGS += $(RELEASE_FLAGS)
all: $(TARGET_PROGRAM)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET_PROGRAM)

$(TARGET_PROGRAM): $(OBJ)
	$(CC) -o $(TARGET_PROGRAM) $(OBJ) $(LIB_LUA)

main.o: main.c
	$(CC) $(CFLAGS) $(INC_LUA) -c main.c -o main.o

clean:
	@echo Cleaning up...
	@rm -f *.o
	@rm -f $(TARGET_PROGRAM)
	@echo Done.
