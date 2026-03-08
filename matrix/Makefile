CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = matrix
SRC = matrix.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean