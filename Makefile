CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: main

main: main.o predictors.o
	$(CXX) $(CXXFLAGS) -o main main.o predictors.o

main.o: main.cpp predictors.h
	$(CXX) $(CXXFLAGS) -c main.cpp

predictors.o: predictors.cpp predictors.h
	$(CXX) $(CXXFLAGS) -c predictors.cpp

clean:
	rm -f main *.o

