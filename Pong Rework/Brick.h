#ifndef BRICK_H_
#define BRICK_H_

#include "pre.h"

class CBrick {
    private:
        RectangleShape brick;

    public:
        void setPos(Vector2f pos) {
            brick.setPosition(pos);
        }
        RectangleShape getBrick() {
            return brick;
        }

        CBrick(Vector2f pos) {
            brick.setSize(SIZE_BRICK);
            brick.setPosition(pos);
            brick.setFillColor(Color::Blue);
            brick.setOutlineThickness(-5);
            brick.setOutlineColor(Color::Black);
        }

        void draw(RenderWindow &window) {
            window.draw(brick);
        }
};

#endif // !BRICK_H_