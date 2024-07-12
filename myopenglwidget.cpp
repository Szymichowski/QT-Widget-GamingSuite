// myopenglwidget.cpp
#include "myopenglwidget.h"
#include <QMouseEvent>
#include <QKeyEvent>

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent), m_controller(&m_model), m_gridSpacing(0.1f), m_aspectRatio(1.0f)
{
    setFocusPolicy(Qt::StrongFocus);
}

void MyOpenGLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void MyOpenGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawCube();
}

void MyOpenGLWidget::resizeGL(int w, int h) {
    int size = qMin(w, h);
    glViewport((w - size) / 2, (h - size) / 2, size, size);
}

void MyOpenGLWidget::keyPressEvent(QKeyEvent *event) {
    m_controller.handleKeyPress(event->key());
    update();
}

void MyOpenGLWidget::mousePressEvent(QMouseEvent *event) {
    float x = (2.0f * event->x()) / width() - 1.0f;
    float y = 1.0f - (2.0f * event->y()) / height();
    m_controller.handleMousePress(x, y);
    update();
}

void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *event) {
    float x = (2.0f * event->x()) / width() - 1.0f;
    float y = 1.0f - (2.0f * event->y()) / height();
    m_controller.handleMouseMove(x, y);
    update();
}

void MyOpenGLWidget::drawGrid() {
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);

    for (float x = -1.0f; x <= 1.0f; x += m_gridSpacing) {
        glVertex2f(x, -1.0f);
        glVertex2f(x, 1.0f);
    }

    for (float y = -1.0f; y <= 1.0f; y += m_gridSpacing) {
        glVertex2f(-1.0f, y);
        glVertex2f(1.0f, y);
    }

    glEnd();
}

void MyOpenGLWidget::drawCube() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    float x = m_model.getX();
    float y = m_model.getY();
    float size = m_model.getSize();
    glVertex2f(x - size, y - size);
    glVertex2f(x + size, y - size);
    glVertex2f(x + size, y + size);
    glVertex2f(x - size, y + size);
    glEnd();
}
