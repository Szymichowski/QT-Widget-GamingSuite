#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include "grid.h"

class MyOpenGLWidget : public Grid
{
    Q_OBJECT

public:
    MyOpenGLWidget(QWidget *parent = nullptr);
    ~MyOpenGLWidget();

protected:
    void initializeGL() override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    float blockX;
    float blockY;
    float blockSize;

    void drawGrid() override; // Implementierung der reinen virtuellen Methode
};

#endif // MYOPENGLWIDGET_H
