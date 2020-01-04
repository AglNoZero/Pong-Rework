#ifndef CONTROL_H_
#define CONTROL_H_

#include "pre.h"
#include "Ball.h"

class CControl {
    public:
        void control(CPaddle &paddle, CBall &ball, CWall &wall) {
            if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::Left)) {
                paddle.moveLeft();
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right)) {
                paddle.moveRight();
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
                if (paddle.getPlayerServe()) {
                    paddle.setPlsyerServe(false);
                    ball.setDir(UP);
                }
            }
			if (Keyboard::isKeyPressed(Keyboard::Key::R)) {
				paddle.setAutoRun(true);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::T)) {
				paddle.setAutoRun(false);
			}

            if (!paddle.getVectorBonus().empty()) {
                vector<CBonus> vBonus = paddle.getVectorBonus();
                for (int i = 0; i < vBonus.size(); i++) {
                    switch (vBonus[i].getType()) {
                        case TYPE1: {
                            if (!paddle.getPlayerServe()) {
                                paddle.setSize(Vector2f(SIZE_PADDLE.x/2, SIZE_PADDLE.y));
                            }
                            vBonus.erase(vBonus.begin() + i);
                            paddle.delBonus(i);
                        } break;

                        case TYPE2: {
                            paddle.setSpeed(0);
                            vBonus.erase(vBonus.begin() + i);
                            paddle.delBonus(i); 
                        } break;
                    }
                }

                if (Keyboard::isKeyPressed(Keyboard::Key::Num0) && !paddle.getPlayerServe()) {
                    for (int i = 0; i < vBonus.size(); i++) {
                        if (vBonus[i].getType() == TYPE0) {
                            if (ball.getBall().getSize().x < 2 * SIZE_BALL.x) {
                                ball.setSize(Vector2f(2 * SIZE_BALL.x, 2 * SIZE_BALL.y));
                            }
                            vBonus.erase(vBonus.begin() + i);
                            paddle.delBonus(i);
                        }
                    }
                }
                // if (Keyboard::isKeyPressed(Keyboard::Key::Num1) && !paddle.getPlayerServe()) {
                //     for (int i = 0; i < vBonus.size(); i++) {
                //         if (vBonus[i].getType() == TYPE1) {
                //             paddle.setSize(Vector2f(SIZE_PADDLE.x/2, SIZE_PADDLE.y));
                //             vBonus.erase(vBonus.begin() + i);
                //             paddle.delBonus(i);
                //         }
                //     }
                // }
                // if (Keyboard::isKeyPressed(Keyboard::Key::Num2) && !paddle.getPlayerServe()) {
                //     for (int i = 0; i < vBonus.size(); i++) {
                //         if (vBonus[i].getType() == TYPE2) {
                //             paddle.setSpeed(0);
                //             vBonus.erase(vBonus.begin() + i);
                //             paddle.delBonus(i);
                //         }
                //     }
                // }
                
                if (Keyboard::isKeyPressed(Keyboard::Key::Num3) && !paddle.getPlayerServe()) {
                    for (int i = 0; i < vBonus.size(); i++) {
                        if (vBonus[i].getType() == TYPE3) {
                            ball.setSpeed(Vector2f(ball.getSpeed().x * 0.5, ball.getSpeed().y * 0.5));
                            vBonus.erase(vBonus.begin() + i);
                            paddle.delBonus(i);
                        }
                    }
                }
                if (Keyboard::isKeyPressed(Keyboard::Key::Num4) && !paddle.getPlayerServe()) {
                    for (int i = 0; i < vBonus.size(); i++) {
                        if (vBonus[i].getType() == TYPE4) {
                            paddle.setupRocket(wall);
                            vBonus.erase(vBonus.begin() + i);
                            paddle.delBonus(i);
                        }
                    }
                }
            }
        }
};

#endif // !CONTROL_H_