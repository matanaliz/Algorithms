CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)

LevenshteinDistance.o : LevenshteinDistance.cpp
	$(CC) $(CFLAGS) LevenshteinDistance.cpp 

all : LevenshteinDistance.o
	$(CC) $(LFLAGS) LevenshteinDistance.o -o levenshtein_distance

clean: 
	\rm *.o levenshtein_distance
