/**
 * plane.h
 * -------------------------------
 * Defines a class which encapsulates our airplane logic
 *
 * Works in conjunction with class VectorOperations to compute updated
 * OpenGL after each button press during the main run loop.
 *
 * @author Paul Lambert <lamber10 @ illinois.edu>
 * @package mp2
 * @note CS418 spring 2012 @ UIUC MP2
 */

#ifndef mp2_plane_h
#define mp2_plane_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <unistd.h>
#include <math.h>

#include "vector_operations.h"


/**
 * Singleton class to act as an intermediary between raw matrix operations
 * via VectorOperation (a dependency) and OpenGL in main.cpp
 */
class Plane
{
    // how fast we can zoom around!
    float velocity;
    
    // our current position, and gluLookAt vectors
    GLfloat *position, *v_up, *v_forward, *v_right;
    
    // a pointer to our mathematical genius friend, Mr. Wizard
    VectorOperations *wizard;
    
    
    
public:
    
    /**
     * Constructor for our Plane class. 
     *
     * Takes initializing values, including its starting position, 
     * world-wise vector orientation, and speed into memory so that 
     * they may be operated upon
     */
    Plane(GLfloat initial[], float velocity,
          GLfloat v_up[], GLfloat v_forward[], GLfloat v_right[]);
    
    /**
     * Calculates the next position of our airplane for our timer 
     * callback function, using the addition of our current position
     * with the product of our current direction and velocity
     *
     * @note changes internal state of the singleton object 
     */
    void move();
    
    /**
     * Calculates our new vector orientation after rolling.
     *
     * @note changes internal state of the singleton object 
     * @param theta the amount of radians by which we roll
     */
    void roll(float theta);
    
    /**
     * Calculates our new vector orientation after pitching.
     *
     * @note changes internal state of the singleton object 
     * @param theta the amount of radians by which we pitch
     */
    void pitch(float theta);
    
    /**
     * Provides our current position back to OpenGL through a reference
     * variable so that we may be rendered upon a frame!
     *
     * @param look reference to a size-3 vector to be populated
     */
    void getPosition(GLfloat *look);
    
    /**
     * Provides our current destination back to OpenGL through a reference
     * variable so that we may be accurately upon our way!
     *
     * @param dest reference to a size-3 vector to be populated
     */
    void getDestination(GLfloat *dest);
    
    /**
     * Provides our current 'up' vector back to OpenGL through a reference
     * variable so that we may avoid vertigo from being inverted!
     *
     * @param up reference to a size-3 vector to be populated
     */
    void getUp(GLfloat *up);
};

#endif
