CXX=g++ 
CXXFLAGS = -g --std=c++20 -Wall

all: game game_set

game_set: card.o main_set.o
	${CXX} ${CXXFLAGS} card.o main_set.o -o game_set

game: card.o card_list.o main.o
	${CXX} ${CXXFLAGS} card.o card_list.o main.o -o game

test: test.o card.o card_list.o
	${CXX} ${CXXFLAGS} test.o card.o card_list.o -o test

tests: card.o card_list.o tests.o
	${CXX} ${CXXFLAGS} card.o card_list.o tests.o -o tests
	./tests

main_set.o: main_set.cpp
	${CXX} ${CXXFLAGS} main_set.cpp -c

main.o: main.cpp
	${CXX} ${CXXFLAGS} main.cpp -c

test.o: test.cpp
	${CXX} ${CXXFLAGS} test.cpp -c
	
tests.o: tests.cpp
	${CXX} ${CXXFLAGS} tests.cpp -c

card_list.o: card_list.cpp card_list.h
	${CXX} ${CXXFLAGS} card_list.cpp -c

card.o: card.cpp card.h
	${CXX} ${CXXFLAGS} card.cpp -c

clean:
	rm game_set game *.o
