//model.cpp
#include "model.h"
#include <cmath>

Model::Model() : m_x(0.0f), m_y(0.0f), m_size(0.05f) {}

void Model::moveLeft(float distance) { m_x -= distance; }
void Model::moveRight(float distance) { m_x += distance; }
void Model::moveUp(float distance) { m_y += distance; }
void Model::moveDown(float distance) { m_y -= distance; }

void Model::setPosition(float x, float y) {
    m_x = x;
    m_y = y;
}

void Model::snapToGrid(float gridSpacing) {
    m_x = std::round(m_x / gridSpacing) * gridSpacing;
    m_y = std::round(m_y / gridSpacing) * gridSpacing;
}
