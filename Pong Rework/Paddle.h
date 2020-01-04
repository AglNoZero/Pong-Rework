#ifndef PADDLE_H_
#define PADDLE_H_

#include "pre.h"
#include "Ball.h"
#include "Wall.h"
#include "ListRocket.h"

class CPaddle {
    private:
		bool isAutoRun;
        RectangleShape paddle;
        float speed;
        bool playerServe;
        int score;
        int life;
        Font font;
        Text textLife;
        Text textBonus;
        void setupText() {
            if (!font.loadFromFile("Fonts/BebasNeue-Regular.ttf")) {
                cout << "Can't load font BebasNeue-Regular.ttf\n";
            }

            textLife.setFont(font);
            textLife.setString(to_string(score));
            textLife.setCharacterSize(30);
            textLife.setPosition(BEGINNING_POS_TEXT);

            textBonus.setFont(font);
            textBonus.setString(to_string(score));
            textBonus.setCharacterSize(20);
            textBonus.setString("");
        }
        vector<CBonus> vectorBonus;
        CListRocket rockets;

    public:
        void setupRocket(CWall wall) {
            rockets.setupRocket(wall);
        }
        void setSize(Vector2f a) {
            paddle.setSize(a);
        }
        vector<CBonus> getVectorBonus() {
            return vectorBonus;
        }
        RectangleShape getPaddle() {
            return paddle;
        }
        float getSpeed() {
            return speed;
        }
        void setSpeed(float a) {
            speed = a;
        }
        bool getPlayerServe() {
            return playerServe;
        }
        int getScore() {
            return score;
        }
        int getLife() {
            return life;
        }
        void setPlsyerServe(bool a) {
            playerServe = a;
        }
        void setScore(int a) {
            score = a;
        }
        void setLife(int a) {
            life = a;
        }
		bool getAutoRun() {
			return isAutoRun;
		}
		void setAutoRun(bool a) {
			isAutoRun = a;
		}

        CPaddle() {
			isAutoRun = false;
            paddle.setSize(SIZE_PADDLE);
            paddle.setPosition(BEGINNING_POS_PADDLE);
			paddle.setFillColor(Color::Color(255, 126, 0, 100));
            setSpeed(SPEED_PADDLE);
            setLife(3);
            setScore(0);
            setPlsyerServe(false);
            setupText();
            // rockets = NULL;
        }

        void drawText(RenderWindow &window) {
            string meoMeo = "Life: " + to_string(life);
            textLife.setString(meoMeo);
            window.draw(textLife);
            window.draw(textBonus);
        }

        void moveLeft() {
            if (paddle.getPosition().x > 0) {
                paddle.move(-speed, 0);
            }
        }

        void moveRight() {
            if (paddle.getPosition().x < WIDTH_DISPLAY - paddle.getSize().x) {
                paddle.move(speed, 0);
            }
        }

        void ifCollisionBonus(CWall &wall) {
            vector<CBonus> bonusArray = wall.getBonusItems();
            for (int i = 0; i < bonusArray.size(); i++) {
                if (paddle.getGlobalBounds().intersects(bonusArray[i].getBonus().getGlobalBounds())) {
                    int type = bonusArray[i].getType();
                    string str;
                    switch (type) {
                        case 0: {
                            str = "x2 size ball";
                        } break;

                        case 1: {
                            str = "x0,5 size paddle";
                        } break;

                        case 2: {
                            str = "frezee paddle";
                        } break;

                        case 3: {
                            str = "x0.5 speed ball";
                        } break;

                        case 4: {
                            str = "Rocket";
                        } break;
                    }
                    textBonus.setPosition(bonusArray[i].getBonus().getPosition().x, bonusArray[i].getBonus().getPosition().y - 50);
                    textBonus.setString(str);
                    if (vectorBonus.empty()) {
                        bonusArray[i].setPos(Vector2f(SIZE_BONUS.x, HEIGHT_DISPLAY - SIZE_BONUS.y));
                    }
                    else {
                        bonusArray[i].setPos(Vector2f(vectorBonus[vectorBonus.size() - 1].getBonus().getPosition().x + 5 + SIZE_BONUS.x, HEIGHT_DISPLAY - SIZE_BONUS.y));
                    }
                    vectorBonus.push_back(bonusArray[i]);
                    wall.delBonus(i);
                    return;
                }
            }
        }

        void delBonus(int n) {
            textBonus.setString("");
            vectorBonus.erase(vectorBonus.begin() + n);
        }

        void draw(RenderWindow &window, CWall &wall) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(0, BEGINNING_POS_PADDLE.y + SIZE_PADDLE.y)),
                sf::Vertex(sf::Vector2f(WIDTH_DISPLAY, BEGINNING_POS_PADDLE.y + SIZE_PADDLE.y))
            };
            window.draw(line, 2, sf::Lines);
            drawText(window);
            window.draw(paddle);
            for (int i = 0; i < vectorBonus.size(); i++) {
                if (vectorBonus[i].getType() != TYPE1 && vectorBonus[i].getType() != TYPE2)
                vectorBonus[i].draw(window);
            }
            rockets.logic(wall);
            rockets.draw(window);
        }
};

#endif // !PADDLE_H_
