/*
 * Sun.h
 *
 *  Created on: Jan 19, 2015
 *      Author: northpole
 */

#ifndef SUN_H_
#define SUN_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <unistd.h>
#include <math.h>

#include "vector_operations.h"
#define PI 3.1415

static float flickerValue = 0.0;

class Sun {

public:

	Sun();

	void display();
};

#endif /* SUN_H_ */
