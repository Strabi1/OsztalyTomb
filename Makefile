
#SHELL = /bin/sh
#SHELL = bash

PROJECT_NAME := Ember
SRC_DIR := ./Sources
BUILD_DIR := ./Build
OBJ_DIR := $(BUILD_DIR)/Obj
FULL_PROJ := $(BUILD_DIR)/$(PROJECT_NAME)

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

LDFLAGS :=
CPPFLAGS := -Wall
CXXFLAGS :=
INC := -I./Includes

RM := rd /s /q
MKRIR := mkdir

#.PHONY: directories

all: directories program run

program: $(OBJ_FILES)
	g++ $(LDFLAGS) -o $(FULL_PROJ) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -std=c++2a $(CPPFLAGS) $(CXXFLAGS) $(INC) -c -o $@ $<

directories: $(BUILD_DIR) $(OBJ_DIR)


$(BUILD_DIR):
	$(MKRIR) "$(BUILD_DIR)"

$(OBJ_DIR):
	$(MKRIR) "$(OBJ_DIR)"

run:
	@echo --------------------------------------------
	@echo $(PROJECT_NAME).exe:
	@$(FULL_PROJ).exe

clean:
	$(RM) "$(BUILD_DIR)"