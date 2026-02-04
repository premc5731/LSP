TARGET = app

CFLAGS = -Wall -Wextra -O2

CC = gcc

$(TARGET): lib
	$(CC) problem_5.c -L. -lmathlib -o $(TARGET)

lib: math.h
	$(CC) math.c -c -o libmathlib.o
	ar rcs libmathlib.a libmathlib.o

clean:
	rm -f $(TARGET)
	rm -f libmathlib.a
	rm -f libmathlib.o

run:
	./$(TARGET)