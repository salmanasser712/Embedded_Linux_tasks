

SOURCES := main.cpp

OBJECTS := $(SOURCES:.cpp=.o)

INCLUDE_FILE := -IVector.h 

build: $(OBJECTS)
	g++ $^ $(INCLUDE_FILE) -o output.exe


%.o: %.cpp
	g++ -MMD $(CPPFLAGS) -c  $< -o $@



-include $(OBJECTS:.o=.d)

clean:
	rm -f *.o *.d

check:
	cppcheck --verbose --addon=misra.json  --checkers-report=checkers_report.txt  Vector.c Vector.h
#	cppcheck  --addon=misra.json --std=c++11 --enable=all --suppress=missingIncludeSystem --force  --check-level=exhaustive --checkers-report=cppcheck_result.txt $(INCLUDE_FILE) $(SOURCES)