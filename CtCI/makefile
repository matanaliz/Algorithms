CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c -g
LFLAGS = -std=c++11 -Wall
OBJS = main.o ctci_chapter_one.o ctci_chapter_two.o

all: ctci 

ctci : ctci.o main.o
	$(CC) $(LFLAGS) $(OBJS) -o ctci

ctci.o : ctci_chapter_one.cpp ctci_chapter_one.h ctci_chapter_two.cpp ctci_chapter_two.h
	$(CC) $(CFLAGS) ctci_chapter_one.cpp ctci_chapter_two.cpp

main.o : main.cpp ctci_chapter_one.h ctci_chapter_two.h
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm -f *.o ctci
