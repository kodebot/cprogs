# It uses the wildcard and patsubst features of the make utility to automatically 
# include .c and .h files in the current directory, meaning when you add new code files to your directory, 
# you won't have to update the Makefile. 
# However, if you want to change the name of the generated executable, libraries, or compiler flags, 
# you can just modify the variables.
# https://stackoverflow.com/a/1484873/3208697

TARGET = program 
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
