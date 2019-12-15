#ifndef ROCKET_H_
#define ROCKET_H_

#include "pre.h"

class CRocket {
    private: 
        CircleShape triangle;
        Vector2f speed;

    public:
        CircleShape getTriangle() {
            return triangle;
        }
        void setPos(Vector2f a) {
            triangle.setPosition(a);
        }

        CRocket() {
            triangle = CircleShape(20, 3);
            triangle.setFillColor(Color::Yellow);
            speed = SPEED_ROCKET;
        }

        void move() {
            triangle.move(speed);
            speed.x *= 110/100;
            speed.y *= 110/100;
        }

        void draw(RenderWindow &window) {
            window.draw(triangle);
        }

        // bool isCollision(CWall &wall) {
        //     vector<CBrick> vectorBrick;
        //     for (int i = 0; i < )
        // }
};

#endif // !ROCKET_H_