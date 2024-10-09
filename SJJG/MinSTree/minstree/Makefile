CXX = g++
CXXFLAGS = -std=c++11

all: myprogram

myprogram: main.o graph.o
	$(CXX) $(CXXFLAGS) $^ -o $@     

main.o: main.cpp graph.h
	$(CXX) $(CXXFLAGS) -c $<

graph.o: graph.cpp graph.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o myprogram
