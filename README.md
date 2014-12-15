## Intro
This is a basic flight simulator written in C++ using OpenGL for the [introductory computer graphics class (CS 418) at University of Illinois](http://graphics.cs.illinois.edu). Consequently, this code was originally written sometime in the spring of 2012; I've merely cleaned it up a little and thrown it on GitHub.

## Building and Running
To build on OS X or Linux, simply run `make` and execute with `./flightsim`

To play, you can use either the `arrow keys` or `WASD`.
The inundation levels can be changed with the `+` and `-` keys.
The poly size can be increased with `f` and decreased with `c`.

To exit, type `C-c` in your terminal.

You can remove the object files etc by running `make clean`.

## Additional notes
I just now added some `#ifdef` protection in the header files and `uname -s` checks in the Makefile, so this program should compile out-of-the-box on a Linux machine. If you have any issues, please report them (or better yet, submit a fix!) and I'll integrate changes.

The in-file documentation may be a bit wordy and odd. Keep in mind this project was likely written the night before it was due (and thereby fueled by several pots of coffee).
