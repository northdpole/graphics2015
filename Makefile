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

# The compiling step
$(EXENAME) : $(OBJS)
	$(LINK) $(LINKOPTS) $(EXENAME) $(OBJS) -framework GLUT -framework OpenGL #-lglut -lGLEW

# Object files
flightsim.o : flightsim.cpp
	$(CC) $(CCOPTS) flightsim.cpp
plane.o : plane.cpp
	$(CC) $(CCOPTS) plane.cpp
vector_operations.o : vector_operations.cpp
	$(CC) $(CCOPTS) vector_operations.cpp

clean :
	rm -f *.o $(EXENAME) 2>/dev/null


