CC=g++
CFLAGS= -c -std=c++11 -Wall -pedantic -pthread

CplusPlus11Review: main.o
	$(CC) -pthread -o bin/CplusPlus11Review main.o

main.o: main.cpp Car.o Dog.o Containers.o InitializerLists.o Tuples.o
	$(CC) $(CFLAGS) main.cpp

Car.o: Car.hpp
	$(CC) $(CFLAGS) Car.hpp

Dog.o: Dog.hpp
	$(CC) $(CFLAGS) Dog.hpp

Containers.o: Containers.hpp
	$(CC) $(CFLAGS) Containers.hpp

InitializerLists.o: InitializerLists.hpp
	$(CC) $(CFLAGS) InitializerLists.hpp

Tuples.o: Tuples.hpp
	$(CC) $(CFLAGS) Tuples.hpp
