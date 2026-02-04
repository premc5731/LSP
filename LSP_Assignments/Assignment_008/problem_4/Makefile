CC = gcc

TARGET = app

BUILD_DIR = build

CFLAGS = -Wall -Wextra -O2

SRC = main.c

$(BUILD_DIR)/$(TARGET): main.o helper.o
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/helper.o -o $(BUILD_DIR)/$(TARGET)

main.o: main.c helper.h
	mkdir -p $(BUILD_DIR)
	$(CC) main.c -c -o $(BUILD_DIR)/main.o

helper.o: helper.c helper.h
	mkdir -p $(BUILD_DIR)
	$(CC) helper.c -c -o $(BUILD_DIR)/helper.o

clean:
	rm -f $(BUILD_DIR)/$(TARGET)
	rm -f $(BUILD_DIR)/main.o
	rm -f $(BUILD_DIR)/helper.o
	rmdir $(BUILD_DIR)

run:
	./$(BUILD_DIR)/$(TARGET)

