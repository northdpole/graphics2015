# Makefile for OpenGL flight simulator
# ------------------------------------

# Object files list
OBJS = flightsim.o plane.o vector_operations.o

# Executable name
EXENAME = flightsim

# Macros
CC = g++
CCOPTS = -c -g -O0 -Wall -Wno-deprecated
LINK = g++
LINKOPTS = -o

all : $(EXENAME)

# Testing for OS X v Linux
OS = $(shell uname -s)

ifeq ($(OS), Darwin)
	LIBS = -framework GLUT -framework OpenGL -framework Cocoa
else
	LIBS = -lglut -lGLEW
endif

# The compiling step
$(EXENAME) : $(OBJS)
	$(LINK) $(LINKOPTS) $(EXENAME) $(OBJS) $(LIBS)

# Object files
flightsim.o : flightsim.cpp
	$(CC) $(CCOPTS) flightsim.cpp
plane.o : plane.cpp
	$(CC) $(CCOPTS) plane.cpp
vector_operations.o : vector_operations.cpp
	$(CC) $(CCOPTS) vector_operations.cpp

clean :
	rm -f *.o $(EXENAME) 2>/dev/null


