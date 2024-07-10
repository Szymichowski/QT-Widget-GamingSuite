#include "myopenglwidget.h"
#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Erstellen Sie das Hauptfenster
    QWidget mainWindow;
    mainWindow.setFixedSize(820, 820);  // Quadratisches Fenster

    // Erstellen Sie das OpenGL-Widget
    MyOpenGLWidget *glWidget = new MyOpenGLWidget(&mainWindow);
    glWidget->setGeometry(10, 10, 800, 800);  // Set the widget to be slightly inset
    glWidget->setFocusPolicy(Qt::StrongFocus);  // Allow the widget to receive key focus


    mainWindow.show();
    glWidget->setFocus();

    return a.exec();
}

/*
#include "myopenglwidget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyOpenGLWidget w;
    w.resize(800, 600);
    w.show();
    return a.exec();
}
*/
