// controller.cpp
#include "controller.h"
#include "model.h"
#include <QWidget>

Controller::Controller(Model* model) : m_model(model), m_isFullscreen(false)
{

}

void Controller::handleKeyPress(int key) {
    const float moveDistance = 0.1f; // Anpassen nach Bedarf
    switch (key) {
    case Qt::Key_Left:
        m_model->moveLeft(moveDistance);
        break;
    case Qt::Key_Right:
        m_model->moveRight(moveDistance);
        break;
    case Qt::Key_Up:
        m_model->moveUp(moveDistance);
        break;
    case Qt::Key_Down:
        m_model->moveDown(moveDistance);
        break;
    case Qt::Key_F:
        toggleFullscreen(true);
        break;
    case Qt::Key_Escape:
        toggleFullscreen(false);
        break;
    }
    m_model->snapToGrid(moveDistance);
}

void Controller::toggleFullscreen(bool enterFullscreen) {
    // Diese Methode muss angepasst werden, um auf das Fenster zuzugreifen
    // Möglicherweise müssen Sie einen Pointer zum Hauptfenster übergeben
    if (enterFullscreen && !m_isFullscreen) {
        //window->showFullScreen();
        m_isFullscreen = true;
    } else if (!enterFullscreen && m_isFullscreen) {
        //window->showNormal();
        m_isFullscreen = false;
    }
}

void Controller::handleMousePress(float x, float y) {
    m_model->setPosition(x, y);
    m_model->snapToGrid(0.1f); // Anpassen nach Bedarf
}

void Controller::handleMouseMove(float x, float y) {
    if (QWidget::mouseGrabber()) { // Prüfen, ob Maus gedrückt ist
        m_model->setPosition(x, y);
        m_model->snapToGrid(0.1f); // Anpassen nach Bedarf
    }
}


