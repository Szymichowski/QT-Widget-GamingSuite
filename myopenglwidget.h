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
    void resizeGL(int w, int h) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void toggleFullscreen();
    void drawGrid();

    float blockX;
    float blockY;
    float blockSize;    
    bool m_isFullscreen;
    QRect m_windowedGeometry;
};

#endif // MYOPENGLWIDGET_H
