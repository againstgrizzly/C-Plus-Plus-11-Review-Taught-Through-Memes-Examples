CC=g++

CFLAGS= -c -std=c++11 -Wall -pedantic

all: hello

hello: main.o
	$(CC) main.o -Wc++11-extensions

main.o: main.cpp Car.o Dog.o
	$(CC) $(CFLAGS) main.cpp

Car.o: Car.hpp
	$(CC) $(CFLAGS) Car.hpp

Dog.o: Dog.hpp
	$(CC) $(CFLAGS) Dog.hpp

# clean: 
# 	rm -rf 