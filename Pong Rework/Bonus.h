#ifndef BONUS_H_
#define BONUS_H_

#include "pre.h"
#include "Ball.h"

class CBonus {
    private:
        RectangleShape bonus;

    public:
        RectangleShape getBonus() {
            return bonus;
        }

        CBonus(Vector2f pos) {
            Texture *image = new Texture;

            bonus.setSize(SIZE_BONUS);
            int i = rand() % 4;
            if (i == 0) {
                // tăng kích thước bóng
                image->loadFromFile("./Items/diamond.png");
            }
            else if (i == 1) {
                // xổ ra 1 đống bóng
                image->loadFromFile("./Items/bomb.png");
            }
            else if (i == 2) {
                // bắn 
                image->loadFromFile("./Items/frezee.png");
            }
            else if (i == 3) {
                // bắn ra tia sét :)
                image->loadFromFile("./Items/dollar.png");
            }
            bonus.setOrigin(X_Y_ORIGIN_BONUS);
            bonus.setTexture(image);
            bonus.setPosition(pos.x + SIZE_BRICK.x/2, pos.y + SIZE_BRICK.y/2);
        }

        void move() {
            bonus.move(0, 0.4f);
        }

        void draw(RenderWindow &window) {
            window.draw(bonus);
        }

        /*
            * mỗi bonus trong vector bonus chỉ được dùng duy nhất 1 lần,,,
            * sau đó phải xóa ngay đi :> 
            * chính xác là xóa đi ngay sau khi  
            * nếu không xóa sẽ làm kích thước bóng x2 nhiều lần, 
            * số bóng cũng sẽ tăng gấp nhiều lần :> 
        */
        // void executeBonus(int type, CBall &ball) {
        //     switch (type) {
        //         case 1: {
        //             // ball.getBall().setSize(Vector2f(SIZE_BALL.x * 2, SIZE_BALL.y * 2));
        //         } break;

        //         // case 2: {
                    
        //         // } break;
        //     }
        // }
};

#endif // !BONUS_H_