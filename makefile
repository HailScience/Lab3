#Makefile

CXX = g++


war: main.o game.o
	${CXX} main.o game.o -o war

main.o: main.cpp
	${CXX} -c main.cpp

game.o: game.cpp game.hpp
	${CXX} -c game.cpp

clean:
	rm *.o war

