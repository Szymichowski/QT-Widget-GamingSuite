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
