#include "myopenglwidget.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <cmath>  // Für die Funktion round()

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : Grid(parent)
    , blockX(0.0f)
    , blockY(0.0f)
    , blockSize(0.05f)
    , m_isFullscreen(false)
{
    setFocusPolicy(Qt::StrongFocus);  // Allow the widget to receive key focus
}

MyOpenGLWidget::~MyOpenGLWidget()
{
}

void MyOpenGLWidget::initializeGL()
{
    // Initialisiert die OpenGL-Funktionen und setzt die Hintergrundfarbe
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void MyOpenGLWidget::paintGL()
{
    // Löscht den Bildschirm mit der Hintergrundfarbe
    glClear(GL_COLOR_BUFFER_BIT);

    // Zeichnet das Raster
    drawGrid();

    // Zeichnet den Block
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(blockX - blockSize, blockY - blockSize);
    glVertex2f(blockX + blockSize, blockY - blockSize);
    glVertex2f(blockX + blockSize, blockY + blockSize);
    glVertex2f(blockX - blockSize, blockY + blockSize);
    glEnd();
}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    int size = qMin(w, h);
    glViewport((w - size) / 2, (h - size) / 2, size, size);
}

void MyOpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        float x = (2.0f * event->x()) / width() - 1.0f;
        float y = 1.0f - (2.0f * event->y()) / height();
        //blockX = round(x / getGridSpacing()) * getGridSpacing();
        //blockY = round(y / getGridSpacing()) * getGridSpacing();
        blockX = round(x / getGridSpacing()) * getGridSpacing() + getGridSpacing() / 2.0f;
        blockY = round(y / getGridSpacing()) * getGridSpacing() + getGridSpacing() / 2.0f;
        update();
    }
}

void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        float x = (2.0f * event->x()) / width() - 1.0f;
        float y = 1.0f - (2.0f * event->y()) / height();
        //blockX = round(x / getGridSpacing()) * getGridSpacing();
        //blockY = round(y / getGridSpacing()) * getGridSpacing();
        blockX = round(x / getGridSpacing()) * getGridSpacing() + getGridSpacing() / 2.0f;
        blockY = round(y / getGridSpacing()) * getGridSpacing() + getGridSpacing() / 2.0f;
        update();
    }
}

void MyOpenGLWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
        blockX -= getGridSpacing();
        break;
    case Qt::Key_Right:
        blockX += getGridSpacing();
        break;
    case Qt::Key_Up:
        blockY += getGridSpacing();
        break;
    case Qt::Key_Down:
        blockY -= getGridSpacing();
        break;
    case Qt::Key_F:
        toggleFullscreen();
        break;
    case Qt::Key_Escape:
        if (m_isFullscreen) {
            toggleFullscreen();
        }
        break;
    default:
        QOpenGLWidget::keyPressEvent(event);
    }
    //blockX = round(blockX / getGridSpacing()) * getGridSpacing();
    //blockY = round(blockY / getGridSpacing()) * getGridSpacing();
    blockX = round((blockX - getGridSpacing() / 2.0f) / getGridSpacing()) * getGridSpacing() + getGridSpacing() / 2.0f;
    blockY = round((blockY - getGridSpacing() / 2.0f) / getGridSpacing()) * getGridSpacing() + getGridSpacing() / 2.0f;
    update();
}

void MyOpenGLWidget::toggleFullscreen()
{
    if (!m_isFullscreen)
    {
        m_windowedGeometry = window()->geometry();
        window()->showFullScreen();
        m_isFullscreen = true;
    }
    else
    {
        window()->showNormal();
        window()->setGeometry(m_windowedGeometry);
        m_isFullscreen = false;
    }
}

void MyOpenGLWidget::drawGrid()
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
