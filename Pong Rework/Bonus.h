#ifndef BONUS_H_
#define BONUS_H_

#include "pre.h"

class CBonus {
    private:
        RectangleShape bonus;
        int type;

    public:
        int getType() {
            return type;
        }
        RectangleShape getBonus() {
            return bonus;
        }
        void setPos(Vector2f a) {
            bonus.setPosition(a);
        }

        CBonus(Vector2f pos) {
            Texture *image = new Texture;

            bonus.setSize(SIZE_BONUS);
            int i = rand() % 5;
            if (i == 0) {
                // Tên lửa
                image->loadFromFile("./Items/rocket.png");
				image->setSmooth(true);
                type = TYPE4;
            }
            else if (i == 1) {
                // Giảm tốc bóng
                image->loadFromFile("./Items/speed down.png");
				image->setSmooth(true);
                type = TYPE3;
            }
            else if (i == 2) {
                // đóng băng paddle cho đến khi mất 1 mạng 
                image->loadFromFile("./Items/frezee.png");
				image->setSmooth(true);
                type = TYPE2;
            }
            else if (i == 3) {
                // Làm nhỏ paddle
                image->loadFromFile("./Items/minimize.png");
				image->setSmooth(true);
                type = TYPE1;
            }
            else if (i == 4) { //Tăng kích thước bóng gấp đôi
                image->loadFromFile("./Items/expand ball.png");
				image->setSmooth(true);
                type = TYPE0;
            }
            bonus.setOrigin(X_Y_ORIGIN_BONUS);
            bonus.setTexture(image);
            bonus.setPosition(pos.x + SIZE_BRICK.x/2, pos.y + SIZE_BRICK.y/2);
        }

        void move() {
            bonus.move(SPEED_BONUS);
        }

        void draw(RenderWindow &window) {
            window.draw(bonus);
        }
};

#endif // !BONUS_H_