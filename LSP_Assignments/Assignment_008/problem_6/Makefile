TARGET = app

SRC = problem_6.c

CFLAGS = -Wall -Wextra -O2

CC = gcc

$(TARGET): so
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

so:
	$(CC) -fPIC -c math.c -o math.o
	$(CC) -shared math.o -o libmathlib.so

clean:
	rm -f $(TARGET)
	rm -f math.o
	rm -f libmathlib.so

run:
	LD_LIBRARY_PATH=. ./$(TARGET)