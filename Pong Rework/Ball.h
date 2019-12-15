#ifndef BALL_H_
#define BALL_H_

#include "pre.h"
#include "Paddle.h"
#include "Wall.h"
#include "cmath"

class CBall {
    private:
        RectangleShape ball;
        Vector2f speed;
        int dir;

        bool isCollision(RectangleShape brick) {
            if (brick.getGlobalBounds().intersects(ball.getGlobalBounds())) {
                return true;
            }
            return false;
        }

    public:
        void setPos(Vector2f a) {
            ball.setPosition(a);
        }
        void setSize(Vector2f a) {
            ball.setSize(a);
        }
        RectangleShape getBall() {
            return ball;
        }
        int getDir() {
            return dir;
        }
        Vector2f getSpeed() {
            return speed;
        }
        void setDir(int a) {
            dir = a;
        }
        void setSpeed(Vector2f a) {
            speed = a;
        }

        CBall() {
            ball.setPosition(BEGINNING_POS_BALL);
            setDir(DOWN);
            setSpeed(Vector2f(SPEED_BALL_X, SPEED_BALL_Y));
            ball.setSize(SIZE_BALL);
            ball.setFillColor(Color::White);
        }

        void drawBall(Vector2f newPos, RenderWindow &window) {
            window.draw(ball);
        }

        void logic(CPaddle &paddle, CWall &wall) {
            // đập biên trên 
            if (ball.getPosition().y <= 0) {
                if (dir == LEFT_UP) {
                    dir = LEFT_DOWN;
                }
                else if (dir == RIGHT_UP) {
                    dir = RIGHT_DOWN;
                }
                else if (dir == UP) {
                    if (rand() % 2 == 0) {
                        dir = LEFT_DOWN;
                    }
                    else {
                        dir = RIGHT_DOWN;
                    }
                }
            }

            // đập biên trái
            if (ball.getPosition().x <= 0) {
                if (dir == LEFT_UP) {
                    dir = RIGHT_UP;
                }
                else if (dir == LEFT_DOWN) {
                    dir = RIGHT_DOWN;
                }
            }

            // đập biên phải
            if (ball.getPosition().x >= WIDTH_DISPLAY - SIZE_BALL.x) {
                if (dir == RIGHT_UP) {
                    dir = LEFT_UP;
                }
                else if (dir == RIGHT_DOWN) {
                    dir = LEFT_DOWN;
                }
            }

            // đập paddle 
            if (ball.getGlobalBounds().intersects(paddle.getPaddle().getGlobalBounds())) {
                if (dir == LEFT_DOWN) {
                    dir = LEFT_UP;
                }
                else if (dir == RIGHT_DOWN) {
                    dir = RIGHT_UP;
                }
                else if (dir == DOWN) {
                    if (rand() % 2 == 0) {
                        dir = LEFT_UP;
                    }
                    else {
                        dir = RIGHT_UP;
                    }
                }
                setSpeed(Vector2f(speed.x * 110/100, speed.y * 110/100));
                paddle.setSpeed(paddle.getSpeed()* 110 / 100);
            }

            // đập gạch
            for (int i = 0; i < wall.getWall().size(); i++) {
                RectangleShape tempBrick = wall.getBrickAt(i).getBrick();
                if (isCollision(tempBrick)) {
					paddle.setScore(paddle.getScore() + 10);
                    float ballX = ball.getPosition().x;
                    float ballY = ball.getPosition().y;
                    float brickX = tempBrick.getPosition().x;
                    float brickY = tempBrick.getPosition().y;

                    // bóng đạp biên trên/dưới của gạch
                    if (ballX >= brickX && ballX <= brickX + SIZE_BRICK.x) {
                        if (dir == RIGHT_DOWN) {
                            dir = RIGHT_UP;
                        }
                        else if (dir == LEFT_DOWN) {
                            dir = LEFT_UP;
                        }
                        else if (dir == RIGHT_UP) {
                            dir = RIGHT_DOWN;
                        }
                        else if (dir == LEFT_UP) {
                            dir = LEFT_DOWN;
                        }
                        else if (dir == UP) {
                            if (rand() % 2 == 0) {
                                dir = LEFT_DOWN;
                            }
                            else {
                                dir = RIGHT_DOWN;
                            }
                        }
                    }

                    // bóng đập biên trái/phải của gạch 
                    else if (ballY >= brickY && ballY <= brickY + SIZE_BRICK.y) {
                        if (dir == RIGHT_DOWN) {
                            dir = LEFT_DOWN;
                        }
                        else if (dir == RIGHT_UP) {
                            dir = LEFT_UP;
                        }
                        else if (dir == LEFT_DOWN) {
                            dir = RIGHT_DOWN;
                        }
                        else if (dir == LEFT_UP) {
                            dir = RIGHT_UP;
                        }
                    }

                    wall.delBrick(i);
                }
            }

            // người chơi bị mất 1 mạng 
            if (ball.getPosition().y >= HEIGHT_DISPLAY - SIZE_BALL.y)  {
                setSpeed(Vector2f(SPEED_BALL_X, SPEED_BALL_Y));
                ball.setSize(SIZE_BALL);

                paddle.setLife(paddle.getLife() - 1);
                paddle.setPlsyerServe(true);
                paddle.setSpeed(SPEED_PADDLE);
                paddle.setSize(SIZE_PADDLE);
            }

            // khi bị mất 1 mạng, bóng mới sẽ đặt trên paddle
            if (paddle.getPlayerServe()) {
                ball.setPosition(paddle.getPaddle().getPosition().x + SIZE_PADDLE.x/2 - SIZE_BALL.x/2, paddle.getPaddle().getPosition().y - SIZE_BALL.x);
            }

            // định hướng di chuyển 
            if(dir == RIGHT_UP) {
                setSpeed(Vector2f(abs(speed.x), -abs(speed.y)));
            }
            else if(dir == RIGHT_DOWN) {
                setSpeed(Vector2f(abs(speed.x), abs(speed.y)));
            }
            else if(dir == LEFT_UP) {
                setSpeed(Vector2f(-abs(speed.x), -abs(speed.y)));
            }
            else if(dir == LEFT_DOWN) {
                setSpeed(Vector2f(-abs(speed.x), abs(speed.y)));
            }
            /*  * trường hợp đi thẳng lên hoặc thẳng xuống được định nghĩa ngay tại hàm move()
                * vì nếu dùng 2 con else if bên dưới, thì tọa độ x của speed sẽ luôn bằng 0
                * else if (dir == UP) {
                *     setSpeed(Vector2f(0, -abs(speed.y)));
                * }
                * else if (dir == DOWN) {
                *     setSpeed(Vector2f(0, abs(speed.y)));
                * }
            */

            // di chuyển 
            if (!paddle.getPlayerServe()) {
                if (dir != UP && dir != DOWN) {
                    ball.move(speed);
                }
                else if (dir == UP) {
                    ball.move(Vector2f(0, -abs(speed.y)));
                }
                else if (dir == DOWN) {
                    ball.move(Vector2f(0, abs(speed.y)));
                }
            }
        }
};

#endif // !BALL_H_