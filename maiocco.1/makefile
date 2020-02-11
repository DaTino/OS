CC = gcc
CFLAGS = -g -Wall -std=c11 -D_BSD_SOURCE
TARGET = bt

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c breadthfirst.c breadthfirst.h displayStats.c displayStats.h stringQueue.c stringQueue.h 

clean:
	$(RM) $(TARGET)
