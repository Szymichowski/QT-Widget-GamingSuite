#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QRect>
class Model;

class Controller {
public:
    Controller(Model* model);
    void handleKeyPress(int key);
    void handleMousePress(float x, float y);
    void handleMouseMove(float x, float y);
    void toggleFullscreen(bool enterFullscreen);

private:
    Model* m_model;
    bool m_isFullscreen;
    QRect m_windowedGeometry;
};

#endif // CONTROLLER_H
