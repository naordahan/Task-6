CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all: Board.o Node.o main.o

Board.o: Board.cpp Board.h 
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o


Node.o: Node.cpp Node.h 
	$(CXX) $(CXXFLAGS) -c Node.cpp -o Node.o


buildAndRun: all main.o
	$(CXX) $(CXXFLAGS) Board.o Node.o main.o
	./a.out


clean:
	rm *.o a.out


