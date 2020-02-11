CC = gcc
CFLAGS = -g -Wall -std=c11
TARGET = bt

all: $(TARGET)

$(TARGET): breadthfirst.c
	$(CC) $(CFLAGS) -o $(TARGET) breadthfirst.c stringQueue.c stringQueue.h

clean:
	$(RM) $(TARGET)
