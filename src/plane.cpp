/**
 * plane.cpp
 * -------------------------------
 * See plane.h for all method documentation
 *
 * @author Paul Lambert <lamber10 @ illinois.edu>
 * @package mp2
 * @note CS418 spring 2012 @ UIUC MP2
 * @see plane.h
 */

#include "plane.h"

Plane::Plane(GLfloat initial[], float velocity,
        GLfloat v_up[], GLfloat v_forward[], GLfloat v_right[])
{
    this->position = initial;
    this->velocity = velocity;
    this->v_up = v_up;
    this->v_forward = v_forward;
    this->v_right = v_right;
}

void Plane::display(double size)
{
        //Begin drawing plygon vertex by vertex
      /*  glBegin (GL_POLYGON);
        glEdgeFlag (0);//If mode is set to wireframe, them this edge is not draw
        glVertex3d(1,0,-1);
        glEdgeFlag (1);//if wire frame, this edage is now supposed to be drawn
        glVertex3d(6,0,-1);
        glVertex3d(6,0,0);
        glVertex3d(1,0,6);
        glVertex3d(0,0,14);
        glVertex3d(-3,0,6);
        glVertex3d(-6,0,0);
        glEdgeFlag (0); //make edge not visible
        glVertex3d(-6,0,-1);
        glEdgeFlag (1);//make edges visible again
        glVertex3d(-1,0,-1);
        glVertex3d(-1,0,0);
        glVertex3d(0,0,0);
        glVertex3d(1,0,0);      
        glEnd();
        glBegin (GL_POLYGON);
        glVertex3d(-2,0,-7);
        glVertex3d(2,0,-7);
        glVertex3d(2,0,0);
        glVertex3d(-2,0,0);             
        glEnd();
        */
	 //draw plane
	GLfloat xpos = 5,ypos=3,zpos=-9;
		    glPushMatrix();
		    xpos = 0;ypos=-0.1;zpos=-0.3;
		    glTranslatef(xpos,ypos,zpos);
		   glutSolidTeapot(size);
		    glPopMatrix();

}
void Plane::move()
{
    position = wizard->add_v(position, wizard->mult_v(v_forward, velocity));
}

void Plane::roll(float theta)
{
    GLfloat *cos_term = wizard->mult_v(v_right, cos(theta));
    GLfloat *sin_term = wizard->mult_v(v_up, sin(theta));
    GLfloat *unit_sum = wizard->unit_v(wizard->add_v(cos_term, sin_term));

    v_right[0] = unit_sum[0];
    v_right[1] = unit_sum[1];
    v_right[2] = unit_sum[2];


    // up = right X forward
    GLfloat *cross = wizard->cross_product(v_right, v_forward);

    v_up[0] = cross[0];
    v_up[1] = cross[1];
    v_up[2] = cross[2];
}
void Plane::pitch(float theta)
{
    GLfloat *pre_normalized =
        wizard->add_v(
                wizard->mult_v(v_forward, cos(theta)),
                wizard->mult_v(v_up, sin(theta))
                );

    GLfloat *f = wizard->unit_v(pre_normalized);
    v_forward[0] = f[0];
    v_forward[1] = f[1];
    v_forward[2] = f[2];

    // up = right X forward
    GLfloat *u = wizard->cross_product(v_right, v_forward);
    v_up[0] = u[0];
    v_up[1] = u[1];
    v_up[2] = u[2];
}

void Plane::getPosition(GLfloat *look)
{
    look[0] = position[0];
    look[1] = position[1];
    look[2] = position[2];
}

void Plane::getDestination(GLfloat *dest)
{
    GLfloat *destVec = wizard->add_v(position, v_forward);
    dest[0] = destVec[0];
    dest[1] = destVec[1];
    dest[2] = destVec[2];
}

void Plane::getUp(GLfloat *up)
{
    up[0] = v_up[0];
    up[1] = v_up[1];
    up[2] = v_up[2];
}
