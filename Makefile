CC		:= g++
C_FLAGS := -std=c++17 -Wall -Wextra -fsanitize=address -g

# BIN		:= bin
SRC		:= 
# INCLUDE	:= include
# LIB		:= lib

# LIBRARIES	:=

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= main.exe
else
EXECUTABLE	:= ./main
endif

all: $(EXECUTABLE)

clean:
	$(RM) $(EXECUTABLE)

run: all
	$(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CC) $(C_FLAGS) $^ -o $@