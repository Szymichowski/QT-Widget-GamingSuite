//grid.cpp
#include "grid.h"

Grid::Grid(QWidget *parent)
    : QOpenGLWidget(parent)
    , aspectRatio(1.0f)
    , gridSpacing(0.05f) // Adjust the spacing as needed
{
}

Grid::~Grid()
{
}

void Grid::drawGrid()
{
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);

    // Zeichnet vertikale Linien
    for (float x = -1.0f; x <= 1.0f; x += getGridSpacing())
    {
        glVertex2f(x, -1.0f);
        glVertex2f(x, 1.0f);
    }

    // Zeichnet horizontale Linien
    for (float y = -1.0f; y <= 1.0f; y += getGridSpacing())
    {
        glVertex2f(-1.0f, y);
        glVertex2f(1.0f, y);
    }

    glEnd();
}


float Grid::getGridSpacing() const
{
    return gridSpacing;
}

void Grid::resizeGL(int w, int h)
{
    float newAspectRatio = static_cast<float>(w) / static_cast<float>(h);
    if (newAspectRatio > aspectRatio) {
        int newWidth = static_cast<int>(h * aspectRatio);
        glViewport((w - newWidth) / 2, 0, newWidth, h);
    } else {
        int newHeight = static_cast<int>(w / aspectRatio);
        glViewport(0, (h - newHeight) / 2, w, newHeight);
    }
}
