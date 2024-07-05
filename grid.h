#ifndef GRID_H
#define GRID_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class Grid : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Grid(QWidget *parent = nullptr);
    virtual ~Grid();

protected:
    void resizeGL(int w, int h) override;
    virtual void drawGrid() = 0; // Reine virtuelle Methode

    float getGridSpacing() const;

private:
    float aspectRatio;
    float gridSpacing;
};

#endif // GRID_H
