CC = gcc

SRC = problem_3.c

BUILD_DIR = build

TARGET = app

CFLAGS = -Wall -Wextra -O2

$(BUILD_DIR)/$(TARGET):
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(BUILD_DIR)/$(TARGET) 

clean:
	rm -f $(BUILD_DIR)/$(TARGET) 
	rmdir  $(BUILD_DIR)

run:
	./$(BUILD_DIR)/$(TARGET) 

help:
	@echo "make : to build process"
	@echo "make clean : to clean the exe"
	@echo "make run : to run the app"
	@echo "Note : exe will be created in build/app"
