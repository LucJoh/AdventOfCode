CC=g++
BUILD_DIR=bin
SRC_DIR=src

.PHONY : all clean $(BUILD_DIR)

all : $(BUILD_DIR) $(BUILD_DIR)/part_1 $(BUILD_DIR)/part_2

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

part_1: $(BUILD_DIR)/part_1

part_2: $(BUILD_DIR)/part_2

$(BUILD_DIR)/part_1 : $(SRC_DIR)/part_1.cpp | $(BUILD_DIR)
	$(CC) -o $@ $< 

$(BUILD_DIR)/part_2 : $(SRC_DIR)/part_2.cpp | $(BUILD_DIR)
	$(CC) -o $@ $< 

clean:
	rm -r $(BUILD_DIR)
