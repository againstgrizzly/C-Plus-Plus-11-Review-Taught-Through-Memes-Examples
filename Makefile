SHELL := /bin/bash
CC=g++
CFLAGS= -c -std=c++11 -Wall -pedantic -pthread

CplusPlus11Review: main.o
	$(CC) -pthread -o bin/CplusPlus11Review main.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp