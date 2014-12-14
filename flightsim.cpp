/**
 * flightsim.cpp
 * -------------------------------
 * See flightsim.h for all method documentation
 *
 * @author Paul Lambert <lamber10 @ illinois.edu>
 * @package mp2
 * @note CS418 spring 2012 @ UIUC MP2
 * @see flightsim.h
 */

#include "flightsim.h"

/**********************
 * GLOBALS
 *********************/
float sealevel;
float polysize;
GLfloat theta = 0.2;

/**
# given coordinates: gluLookAt (0.5, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
#   1. eye[xyz]    -- WORLD coordinates of camera
#   2. look[xyz] -- what we're LOOKING at
#   3. up[xyz]     -- orthogonal to camera, specifies camera's roll
#
# recall that right = look X up
 **/

// initialize lookat vectors & Plane class constructor with given data,
// commented out and explained above.

float velocity = 0.001f;

GLfloat look[] = {0.5, 0.0, 0.25};
GLfloat dest[] = {0.0, 0.0, 0.0};
GLfloat up[]   = {0.0, 0.0, 1.0};

GLfloat v_forward[] = {-1, 0, 0};
GLfloat v_right[]   = {0, 1, 0};

// see plane.h for documentation
Plane airplane(look, velocity, up, v_forward, v_right);

/**********************
 * IMPLEMENTATIONS
 *********************/
int seed(float x, float y)
{
    static int a = 1588635695, b = 1117695901;
    int xi = *(int *)&x;
    int yi = *(int *)&y;
    return ((xi * a) % b) - ((yi * b) % a);
}

void mountain(float x0, float y0, float z0,
        float x1, float y1, float z1,
        float x2, float y2, float z2, float s)
{
    float x01,y01,z01,x12,y12,z12,x20,y20,z20;

    if (s < polysize) {
        x01 = x1 - x0;
        y01 = y1 - y0;
        z01 = z1 - z0;

        x12 = x2 - x1;
        y12 = y2 - y1;
        z12 = z2 - z1;

        x20 = x0 - x2;
        y20 = y0 - y2;
        z20 = z0 - z2;

        float nx = y01*(-z20) - (-y20)*z01;
        float ny = z01*(-x20) - (-z20)*x01;
        float nz = x01*(-y20) - (-x20)*y01;

        float den = sqrt(nx*nx + ny*ny + nz*nz);

        if (den > 0.0) {
            nx /= den;
            ny /= den;
            nz /= den;
        }

        glNormal3f(nx,ny,nz);
        glBegin(GL_TRIANGLES);
        glVertex3f(x0,y0,z0);
        glVertex3f(x1,y1,z1);
        glVertex3f(x2,y2,z2);
        glEnd();

        return;
    }

    x01 = 0.5*(x0 + x1);
    y01 = 0.5*(y0 + y1);
    z01 = 0.5*(z0 + z1);

    x12 = 0.5*(x1 + x2);
    y12 = 0.5*(y1 + y2);
    z12 = 0.5*(z1 + z2);

    x20 = 0.5*(x2 + x0);
    y20 = 0.5*(y2 + y0);
    z20 = 0.5*(z2 + z0);

    s *= 0.5;

    srand(seed(x01,y01));
    z01 += 0.3*s*(2.0*((float)rand()/(float)RAND_MAX) - 1.0);
    srand(seed(x12,y12));
    z12 += 0.3*s*(2.0*((float)rand()/(float)RAND_MAX) - 1.0);
    srand(seed(x20,y20));
    z20 += 0.3*s*(2.0*((float)rand()/(float)RAND_MAX) - 1.0);

    mountain(x0,y0,z0,x01,y01,z01,x20,y20,z20,s);
    mountain(x1,y1,z1,x12,y12,z12,x01,y01,z01,s);
    mountain(x2,y2,z2,x20,y20,z20,x12,y12,z12,s);
    mountain(x01,y01,z01,x12,y12,z12,x20,y20,z20,s);
}

void init(void)
{
    GLfloat white[] = {1.0,1.0,1.0,1.0};
    GLfloat lpos[] = {0.0,1.0,0.0,0.0};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, white);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    glClearColor (0.5, 0.5, 1.0, 0.0);
    // glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    sealevel = 0.0;
    polysize = 0.01;
}

void timerCallBack(int rate)
{
    glutTimerFunc(5, timerCallBack, rate);

    airplane.move();

    airplane.getPosition(look);
    airplane.getDestination(dest);
    airplane.getUp(up);

    glutPostRedisplay();
}

void display(void)
{
    static GLfloat angle = 0.0;

    GLfloat tanamb[]  = {0.2,0.15,0.1,1.0};
    GLfloat tandiff[] = {0.4,0.3,0.2,1.0};

    GLfloat seaamb[]  = {0.0,0.0,0.2,1.0};
    GLfloat seadiff[] = {0.0,0.0,0.8,1.0};
    GLfloat seaspec[] = {0.5,0.5,1.0,1.0};


    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glLoadIdentity ();

    // replace old gluLookAt
    gluLookAt(look[0], look[1], look[2],
            dest[0], dest[1], dest[2],
            up[0],   up[1],   up[2]);

    glTranslatef (-0.5, -0.5, 0.0);

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tanamb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tandiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tandiff);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 10.0);

    mountain(0.0,0.0,0.0, 1.0,0.0,0.0, 0.0,1.0,0.0, 1.0);
    mountain(1.0,1.0,0.0, 0.0,1.0,0.0, 1.0,0.0,0.0, 1.0);

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, seaamb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, seadiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, seaspec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 10.0);

    glNormal3f(0.0,0.0,1.0);

    glBegin(GL_QUADS);
    glVertex3f(0.0,0.0,sealevel);
    glVertex3f(1.0,0.0,sealevel);
    glVertex3f(1.0,1.0,sealevel);
    glVertex3f(0.0,1.0,sealevel);
    glEnd();

    glutSwapBuffers();

    glFlush ();

    angle += 1.0;

    glutPostRedisplay();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(90.0,1.0,0.01,10.0);
    glMatrixMode (GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case '-':
            sealevel -= 0.01;
            break;

        case '+':
        case '=':
            sealevel += 0.01;
            break;

        case 'f':
            polysize *= 0.5;
            break;

        case 'c':
            polysize *= 2.0;
            break;

        case 27:
            exit(0);
            break;

            // roll left
        case 'a':
        case 'A':
            airplane.roll(-theta);
            break;

            // roll right
        case 'd':
        case 'D':
            airplane.roll(theta);
            break;

            // pitch DOWN!!!! assuming we wish to be realistic here, anyway
        case 'w':
        case 'W':
            airplane.pitch(-theta);
            break;

            //pitch UP!!!!!!
        case 's':
        case 'S':
            airplane.pitch(theta);
            break;
    }
}

void keyboard_arrows(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT:
            airplane.roll(-theta);
            break;
        case GLUT_KEY_RIGHT:
            airplane.roll(theta);
            break;

            // real super awesome airplanes IRL have inverted controls!
            // so we will too!
        case GLUT_KEY_UP:
            airplane.pitch(-theta);
            break;
        case GLUT_KEY_DOWN:
            airplane.pitch(theta);
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (600, 450);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("lamber10 - mp2 - cs418[sp12]@uiuc");
    glutTimerFunc(100, timerCallBack, 0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboard_arrows);
    init ();
    glutMainLoop();
    return 0;
}
