SUBMISSION = basic
EXECUTABLE = $(SUBMISSION)
SOURCES    = $(wildcard *.cpp)
OBJECTS    = $(patsubst %,%,${SOURCES:.cpp=.o})
CXX        = g++
CXXFLAGS   = -Wall -g -c -std=c++11 -o
LDFLAGS    = -static-libstdc++
LDLIBS     =
VALFLAGS   = -v --tool=memcheck --leak-check=full --leak-check=yes --tool=memcheck --undef-value-errors=yes --track-origins=yes --show-leak-kinds=all
#-------------------------------------------------------------------------------

#make executable
all: $(EXECUTABLE) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $@ $< -MMD -MF $@.d

	
#link Objects
$(EXECUTABLE) : $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

run:
	./$(EXECUTABLE) 10 1 1
	
pluto:
	PATH=/opt/gcc482/bin:$(PATH);LD_LIBRARY_PATH=/opt/gcc482/lib:$(LD_LIBRARY_PATH);CXX=g++-482;make

#make clean
clean:
	rm -f *.o
	rm -f *.o.d
	rm -f $(EXECUTABLE)


#make valgrind
valgrind:
	valgrind $(VALFLAGS) ./$(EXECUTABLE)

#make submission zip archive for PALME
submission:
	zip $(SUBMISSION).zip *.cpp *.h

.PHONY: clean cleanw submission

#The dependencies:
-include $(wildcard *.d)
