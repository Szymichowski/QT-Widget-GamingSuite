#ifndef MODEL_H
#define MODEL_H

class Model {
public:
    Model();
    void moveLeft(float distance);
    void moveRight(float distance);
    void moveUp(float distance);
    void moveDown(float distance);
    void setPosition(float x, float y);
    void snapToGrid(float gridSpacing);
    float getX() const { return m_x; }
    float getY() const { return m_y; }
    float getSize() const { return m_size; }

private:
    float m_x, m_y, m_size;
};

#endif // MODEL_H
