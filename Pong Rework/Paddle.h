#ifndef PADDLE_H_
#define PADDLE_H_

#include "pre.h"
#include "Ball.h"
#include "Wall.h"

class CPaddle {
    private:
        RectangleShape paddle;
        float speed;
        bool playerServe;
        int score;
        int life;
        vector<CBonus> vectorBonus;

		void setupText() {
			Font font;
			Text text;
			if (!font.loadFromFile("BebasNeue-Regular.ttf")) {
				cout << "Can't load font BebasNeue-Regular.ttf\n";
			}

			text.setFont(font);
			text.setString(to_string(score));
			text.setFillColor(Color::Color(255, 0, 102, 100));
			text.setCharacterSize(100);
			text.setPosition((WIDTH_DISPLAY - text.getGlobalBounds().width)/2, 200);
		}

    public:
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

        CPaddle() {
            paddle.setSize(SIZE_PADDLE);
            paddle.setPosition(BEGINNING_POS_PADDLE);
            paddle.setFillColor(Color::Cyan);
            setSpeed(SPEED_PADDLE);
            setLife(3);
            setScore(0);
            setPlsyerServe(false);
            setupText();
        }

        void drawText(RenderWindow &window) {
            string meoMeo = "Life: " + to_string(life);
			Text text;
            text.setString(meoMeo);
            window.draw(text);
        }

        void moveLeft() {
            if (paddle.getPosition().x > 0) {
                paddle.move(-speed, 0);
            }
        }

        void moveRight() {
            if (paddle.getPosition().x < WIDTH_DISPLAY - SIZE_PADDLE.x) {
                paddle.move(speed, 0);
            }
        }

        void ifCollisionBonus(CWall &wall) {
            vector<CBonus> bonusArray = wall.getBonusItems();
            for (int i = 0; i < bonusArray.size(); i++) {
                if (paddle.getGlobalBounds().intersects(bonusArray[i].getBonus().getGlobalBounds())) {
                    wall.delBonus(i);
                    vectorBonus.push_back(bonusArray[i]);
                    return;
                }
            }
        }

        void draw(RenderWindow &window) {
            drawText(window);
            window.draw(paddle);
        }
};

#endif // !PADDLE_H_
