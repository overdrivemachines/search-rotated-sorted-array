
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

search-rotated-sorted-array: search-rotated-sorted-array.o
	$(CC) $(CFLAGS) -o search-rotated-sorted-array search-rotated-sorted-array.o

search-rotated-sorted-array.o: search-rotated-sorted-array.cpp
	$(CC) $(CFLAGS) -c search-rotated-sorted-array.cpp

clean:
	rm -rf search-rotated-sorted-array search-rotated-sorted-array.o
