/*
 * Sun.cpp
 *
 *  Created on: Jan 19, 2015
 *      Author: northpole
 */

#include "Sun.h"

Sun::Sun() {}

void Sun::display(){

	glPushMatrix();
			GLfloat xpos = 5,ypos=3,zpos=-9;
		    glTranslatef(xpos,ypos,zpos);

		    glutSolidTeapot(2.0);

		    glColor4f(1,1,0,0.5);
			glEnable( GL_BLEND );
			glBlendFunc( GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA );
			glutSolidSphere(20.0+2.0*cos(flickerValue*PI/180),
							 	 	 20.0 + 2.0*cos(flickerValue*PI/180),
							 	 	 20.0 + 2.0*cos(flickerValue*PI/180));

			glColor4f(1.0, 0.5, 0.2,1);
			glEnable( GL_BLEND );
			glBlendFunc( GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA );
			//glTranslated(0.0,0.0,-20.0);
			glutSolidSphere(17.0,17.0,17.0);
			//glTranslated(22.0,1.0,3.0);
		glPopMatrix();

}
