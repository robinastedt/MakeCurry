CC=g++
FLAGS=-Wall -O3 -std=c++14
OUT=curry
SRC=src/TestCurry.cpp

compile: $(SRC)
	$(CC) $(FLAGS) -o $(OUT) $(SRC)