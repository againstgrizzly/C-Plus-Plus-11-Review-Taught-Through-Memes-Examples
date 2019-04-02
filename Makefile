CC=g++

CFLAGS= -c -std=c++11 -Wall -pedantic

all: hello

hello: main.o
	$(CC) main.o -Wc++11-extensions

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

Dog.o: Tuples.hpp
	$(CC) $(CFLAGS) Tuples.hpp

# clean:
# 	rm -rf