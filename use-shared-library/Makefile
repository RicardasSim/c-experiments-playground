CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow
DEBUG_FLAGS   = -O0 -DDEBUG -g
RELEASE_FLAGS = -O3 -DNDEBUG
OBJ = main.o
OBJ_SHARED = testprog-shared.o
TARGET_PROGRAM = testprog
TARGET_SHARED_LIB = libTestprogShared.so

all: exe shared
debug: exe-debug shared-debug

exe: CFLAGS += $(RELEASE_FLAGS)
exe: $(TARGET_PROGRAM)

exe-debug: CFLAGS += $(DEBUG_FLAGS)
exe-debug: $(TARGET_PROGRAM)

shared: CFLAGS += $(RELEASE_FLAGS)
shared: $(TARGET_SHARED_LIB)

shared-debug: CFLAGS += $(DEBUG_FLAGS)
shared-debug: $(TARGET_SHARED_LIB)

$(TARGET_PROGRAM): $(OBJ)
	$(CC) -o $(TARGET_PROGRAM) $(OBJ) -ldl

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

$(TARGET_SHARED_LIB): $(OBJ_SHARED)
	$(CC) -shared -o $(TARGET_SHARED_LIB) $(OBJ_SHARED)

testprog-shared.o: testprog-shared.c
	$(CC) $(CFLAGS) -c testprog-shared.c -o testprog-shared.o

clean:
	@echo Cleaning up...
	@rm -f *.o
	@rm -f $(TARGET_PROGRAM)
	@rm -f $(TARGET_SHARED_LIB)
	@echo Done.
