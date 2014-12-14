This is a basic flight simulator written in C++ using OpenGL for the [introductory computer graphics class (CS 418) at University of Illinois](http://graphics.cs.illinois.edu).

To build on OS X, simply run `make` and execute with `./flightsim`

To build on Linux, you'll need to make a few modifications:
    * change `#include<GLUT/glut.h>` in the headers to `#include<gl/glut.h>`
    * change the Makefile's compiler flags from `-framework GLUT -framework OpenGL` to `-lglut -lGLEW`

(Apple just loves to be different, don't they?)

To play, you can use either the `arrow keys` or `WASD`. The inundation levels can be changed with the `+` and `-` keys.

To exit, type `C-c` in your terminal. You can remove the object files etc by running `make clean`.


(Yes: I know I *could* add `#ifdef`s for the Linux folks, but I seriously doubt anybody's even going to look at this repository...)
