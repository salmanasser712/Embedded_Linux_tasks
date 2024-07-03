

LD_LIBRARIES := -lcurl

CPPFLAGS := -I./include/  

SOURCES := main.cpp DataClass.cpp CurlClass.cpp RapidjsonClass.cpp

OBJECTS := $(SOURCES:.cpp=.o)

STEM := $(basename $@)

vpath %.cpp ./src/ 

build: $(OBJECTS)
	g++  $^ $(LD_LIBRARIES) -o output.exe


%.o: %.cpp
	g++ -MMD $(CPPFLAGS) -c  $< -o $@

-include $(OBJECTS:.o=.d)

clean:
	rm -f *.o *.exe *.d