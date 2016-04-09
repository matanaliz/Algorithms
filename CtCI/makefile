CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c
LFLAGS = -std=c++11 -Wall
OBJS = main.o ctci_chapter_one.o

all: ctci 

ctci : ctci.o main.o
	$(CC) $(LFLAGS) $(OBJS) -o ctci

ctci.o : ctci_chapter_one.cpp ctci_chapter_one.h
	$(CC) $(CFLAGS) ctci_chapter_one.cpp

main.o : main.cpp ctci_chapter_one.h
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o ctci
