//cubebase.cpp
#include "cubebase.h"
#include <GL/gl.h>

CubeBase::CubeBase()
    : blockX(0.0f)
    , blockY(0.0f)
    , blockSize(0.05f)
{

}

void CubeBase::drawCube()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(blockX - blockSize, blockY - blockSize);
    glVertex2f(blockX + blockSize, blockY - blockSize);
    glVertex2f(blockX + blockSize, blockY + blockSize);
    glVertex2f(blockX - blockSize, blockY + blockSize);
    glEnd();
}

