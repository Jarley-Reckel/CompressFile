CXX := g++
LIBS := -lm
SRC := src
OBJ := obj
INC := include
BIN := bin

HDRS := $(wildcard $(INC)/*.hpp)
OBJS := $(HDRS:$(INC)/%.hpp=$(OBJ)/%.o) $(OBJ)/main.o

CFLAGS := -Wall -c -I$(INC) -g

EXE := $(BIN)/main

all: $(EXE)

$(BIN)/main: $(OBJS)
	$(CXX) -pg -o $(BIN)/main $(OBJ)/* $(LIBS)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f $(EXE) $(OBJS)