CXX=clang++-5.0
CPPFLAGS=-std=c++17 

all: Board.o Node.o


 main.o: nain.cpp Board.h
   $(CXX) $(CXXFLAGS) -c main.cpp -o main.o
   
   
Board.o: Board.cpp Board.h
	$(CXX) $(CPPFLAGS) --compile Board.cpp -o Board.o

   
   Node.o: Node.cpp Node.h 
	$(CXX) $(CXXFLAGS) -c Node.cpp -o Node.o
  
  
clean:
	rm *.o a.out
  

buildAndRun: all main.o
	$(CXX) $(CXXFLAGS) Board.o Node.o main.o
	./a.out
  
