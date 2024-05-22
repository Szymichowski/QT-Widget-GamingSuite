#include "myopenglwidget.h"
#include <QMouseEvent>
#include <QKeyEvent>

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , blockX(0.0f)
    , blockY(0.0f)
    , blockSize(0.2f)
{
}

MyOpenGLWidget::~MyOpenGLWidget()
{
}

void MyOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void MyOpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(blockX - blockSize, blockY - blockSize);
    glVertex2f(blockX + blockSize, blockY - blockSize);
    glVertex2f(blockX + blockSize, blockY + blockSize);
    glVertex2f(blockX - blockSize, blockY + blockSize);
    glEnd();
}

void MyOpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        float x = (2.0f * event->x()) / width() - 1.0f;
        float y = 1.0f - (2.0f * event->y()) / height();
        blockX = x;
        blockY = y;
        update();
    }
}

void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        float x = (2.0f * event->x()) / width() - 1.0f;
        float y = 1.0f - (2.0f * event->y()) / height();
        blockX = x;
        blockY = y;
        update();
    }
}

void MyOpenGLWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        blockX -= 5.0f;
        break;
    case Qt::Key_Right:
        blockX += 5.0f;
        break;
    case Qt::Key_Up:
        blockY -= 5.0f;
        break;
    case Qt::Key_Down:
        blockY += 5.0f;
        break;
    default:
        QOpenGLWidget::keyPressEvent(event);
    }
    update();
}
