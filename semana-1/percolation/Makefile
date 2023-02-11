CC = g++
NAME = program
CFLAGS = --std=c++11 -Wall -O2
DEBUG_FLAG =

BUILD_DIR = ./build
INCLUDE_DIR = ./include
RES_DIR = ./src/res
SRC_DIR = ./src

BUILD_FILES = \
	$(BUILD_DIR)/Percolation.o\
	$(BUILD_DIR)/PercolationStats.o\
	$(BUILD_DIR)/WeightedQuickUnion.o\
	$(BUILD_DIR)/main.o


all: $(BUILD_DIR)/$(NAME)

$(BUILD_DIR)/$(NAME): $(BUILD_FILES)
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $(BUILD_DIR)/*.o -o $(BUILD_DIR)/$(NAME)

$(BUILD_DIR)/%.o: $(RES_DIR)/%.cpp $(INCLUDE_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $(DEBUG_FLAG) $< -I $(INCLUDE_DIR) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $(DEBUG_FLAG) $< -I $(INCLUDE_DIR) -o $@

run: all
	$(BUILD_DIR)/$(NAME)

valgrind:
	valgrind --leak-check=full $(BUILD_DIR)/$(NAME)

debug: clean_build var all

var:
	$(eval DEBUG_FLAG = -g)

clean_build:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/*.gcda
	rm -f $(BUILD_DIR)/*.gcno
	rm -f $(BUILD_DIR)/$(NAME)

clean: clean_build

