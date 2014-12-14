/**
 * flightsim.h
 * -------------------------------
 * Main entry point for this CS418-SP12-MP2 project.
 *
 * Contains all the OpenGL code to complete our task, with the assistance
 * of a few included friends.
 *
 * @author Paul Lambert <lamber10 @ illinois.edu>
 * @package mp2
 * @note CS418 spring 2012 @ UIUC MP2
 */

#ifndef mp2_main_h
#define mp2_main_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <unistd.h>
#include <math.h>

#include "plane.h"

/**********************
 * GLOBALS
 *********************/
extern float sealevel;
extern float polysize;

extern GLfloat theta;

/**********************
 * PROTOTYPES
 *********************/

/**
 * Given function.
 *
 * Seeds the random number generator for rendering our lovely mountains.
 */
int seed(float x, float y);

/**
 * Given function.
 *
 * Draws a most lovely mountain given the input coordinates
 */
void mountain(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, float s);

/**
 * Given function
 *
 * Initializes our environment to prepare both you and your graphics card
 * through a beautiful journey across a canyon setting.
 */
void init(void);

/**
 * Modification of the given function
 *
 * In the context of this here project, display() is essentially
 * Bob Ross. No accidents, just happy little mistakes.
 *
 * Flushes some buffers, swaps some other buffers, and then slaps
 * the living devil out of 'em!
 *
 * (I hope you get this reference.)
 */
void display(void);

/**
 * Given function
 *
 * In the event that our spawned window is too skinny or too fat, we have
 * on demand dieting/feasting!
 */
void reshape(int w, int h);

/**
 * Modification of the given function
 *
 * Allowed for typical computer video game style movements around our
 * virtual reality, using wasd / WASD. The airplane changes a static
 * 0.2 radians per push.
 */
void keyboard(unsigned char key, int x, int y);

/**
 * Totally new and AWESOME function!!
 *
 * Not really. Just extended functionality from the above, modified
 * function (namely keyboard(...)) to give the same functionality to
 * the arrow keys. Again, the airplane changes a static 0.2 radians
 * per push.
 */
void keyboard_arrows(int key, int x, int y);

/**
 * Another TOTALLY NEW AND AWESOME function!!
 *
 * Nah, again, this one isn't terribly exciting. It just keeps polling
 * for changes in our aeroplane, and pokes Bob Ross when it's time
 * to enjoy another happy painting.
 */
void timerCallBack(int rate);

#endif


