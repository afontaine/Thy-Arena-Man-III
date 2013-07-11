CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lm -lncurses
SOURCESDIR=./Source/
SOURCES=*.cpp $(SOURCESDIR)/*.cpp $(SOURCESDIR)/Items/*.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
