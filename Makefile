#Hunter Vaccaro
#hpv8hf
#Lab Section 11:00 am
CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -std=c++11
DEBUG = -Wall -g
.SUFFIXES: .o .cpp

huffmandec: huffNode.o huffmandec.o
	$(CXX) $(DEBUG) huffNode.o huffmandec.o

huffmandec.o:huffmandec.cpp 
	$(CXX) -c huffmandec.cpp

huffNode.o:huffNode.cpp huffNode.h
	$(CXX) -c huffNode.cpp 

clean:
	-rm *.o *~ huffmandec.exe
