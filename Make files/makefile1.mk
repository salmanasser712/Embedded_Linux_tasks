testdate: Date.o testDate.o
	g++ -o testdate Date.o testDate.o


Date.o: Date.cpp Date.h
	g++ -c Date.cpp

testDate.o: testDate.cpp Date.h
	g++ -c testDate.cpp