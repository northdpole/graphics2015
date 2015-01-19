/**
 * vector_operations.cpp
 * -------------------------------
 * See vector_operations.h for all method documentation
 *
 * @author Paul Lambert <lamber10 @ illinois.edu>
 * @package mp2
 * @note CS418 spring 2012 @ UIUC MP2
 * @see vector_operations.h
 */

#include "vector_operations.h"

GLfloat* VectorOperations::mult_v(GLfloat vector[], float mult)
{
    GLfloat *multiplied = new GLfloat[3];

    for(int i=0; i<3; i++)
    {
        multiplied[i] = vector[i] * mult;
    }

    return multiplied;
}

GLfloat* VectorOperations::add_v(GLfloat first[], GLfloat second[])
{
    GLfloat *sum = new GLfloat[3];

    for(int i=0; i<3; i++)
    {
        sum[i] = first[i] + second[i];
    }

    return sum;
}

GLfloat* VectorOperations::cross_product(GLfloat a[], GLfloat b[])
{
    GLfloat *cross = new GLfloat[3];

    cross[0] = (a[1] * b[2]) - (a[2]* b[1]);
    cross[1] = (a[2] * b[0]) - (a[0]* b[2]);
    cross[2] = (a[0] * b[1]) - (a[1]* b[0]);

    return cross;
}

GLdouble VectorOperations::norm(GLfloat vector[])
{
    GLdouble pre_square =
        pow(vector[0], 2) +
        pow(vector[1], 2) +
        pow(vector[2], 2);

    return sqrt(pre_square);
}


GLfloat* VectorOperations::unit_v(GLfloat vector[])
{
    GLdouble norm = this->norm(vector);

    GLfloat *unit = new GLfloat[3];
    unit[0] = vector[0] / norm;
    unit[1] = vector[1] / norm;
    unit[2] = vector[2] / norm;

    return unit;
}
