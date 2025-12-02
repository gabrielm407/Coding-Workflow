CC = g++
CFLAGS = -Wall -g
SRC = src/main.cpp src/utils.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = my_cpp_project

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)