#ifndef WALL_H_
#define WALL_H_

#include "Brick.h"
#include "Bonus.h"

class CWall {
    protected:
        vector<CBrick> wall;
        vector<CBonus> bonusItems;

    public:
        vector<CBonus> getBonusItems() {
            return bonusItems;
        }

        CWall() {
            CBrick *temp;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i % 2 == 0) {
                        temp = new CBrick(Vector2f(j * 100/2, i * 50/2));
                    }
                    else {
                        temp = new CBrick(Vector2f(-50/2 + j * 100/2, i * 50/2));
                    }
                    //temp->getBrick().setFillColor(Color(28 * i, 28 * j, 50/2));
                    wall.push_back(*temp);
                }
            }
        }

        void delBrick(int n, RenderWindow &window) {
            // true để test, sửa thành rand() % 2 == 0 ngay khi end game
            if (rand() % 2 == 0) {
                CBonus bonus = CBonus(wall[n].getBrick().getPosition());
                bonusItems.push_back(bonus);
            }
            wall.erase(wall.begin() + n);
        }

        void delBonus(int n) {
            bonusItems.erase(bonusItems.begin() + n);
        }

        CBrick getBrickAt(int n) {
            return wall[n];
        }

        void drawWall(RenderWindow &window) {
            for (int i = 0; i < wall.size(); i++) {
                wall[i].draw(window);
            }
            for (int i = 0; i < bonusItems.size(); i++) {
                bonusItems[i].move();
                bonusItems[i].draw(window);
            }
        }

        vector<CBrick> getWall() {
            return wall;
        }
};

#endif // !WALL_H_