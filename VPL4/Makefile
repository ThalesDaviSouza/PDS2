BUILD_DIR = ./build
CPPFLAGS = -I include

all: vpl_execution 

vpl_execution: $(BUILD_DIR)/main.o $(BUILD_DIR)/list.o
	g++ -o vpl_execution $(BUILD_DIR)/main.o $(BUILD_DIR)/list.o

$(BUILD_DIR)/main.o: ./src/main.cpp ./include/list.hpp | build
	g++ $(CPPFLAGS) -c ./src/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/list.o: ./src/list.cpp ./include/list.hpp | build
	g++ $(CPPFLAGS) -c ./src/list.cpp -o $(BUILD_DIR)/list.o 

build:
	mkdir build