#include "grid.h"

Grid::Grid(QWidget *parent)
    : QOpenGLWidget(parent)
    , aspectRatio(1.0f)
    , gridSpacing(0.1f) // Adjust the spacing as needed
{
}

Grid::~Grid()
{
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

float Grid::getGridSpacing() const
{
    return gridSpacing;
}

