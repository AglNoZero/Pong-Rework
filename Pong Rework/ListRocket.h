#ifndef LIST_ROCKET_H_
#define LIST_ROCKET_H_

#include "pre.h"
#include "Rocket.h"
#include "Wall.h"
#include "cmath"

class CListRocket {
    private:
        vector<CRocket> vectorRocket;

    public:

        void setupRocket(CWall wall) {
            vector<CBrick> vectorBrick = wall.getWall();
            //CBrick *tempB; 
            //for (int i = 0; i < wall.getWall().size(); i++) {
            //    tempB = new CBrick();
            //    *tempB = wall.getWall()[i];
            //    vectorBrick.push_back(*tempB);
            //}
            CRocket *temp;
            for (int i = 0; i < 10; i++) {
                temp = new CRocket();
                temp->setPos(Vector2f(30 + 100 * i, BEGINNING_POS_PADDLE.y + 20 * pow(-1, i)));
                vectorRocket.push_back(*temp);
            }
        }

        bool isCollisionWall(CircleShape triangle, CWall &wall) {
            vector<CBrick> vectorBrick = wall.getWall();
            for (int i = 0; i < vectorBrick.size(); i++) {
                if (triangle.getGlobalBounds().intersects(vectorBrick[i].getBrick().getGlobalBounds())) {
                    wall.delBrick(i);
                    vectorBrick.erase(vectorBrick.begin() + i);
                    return true;
                }
            }
            return false;
        }

        void delRocket(int n) {
            vectorRocket.erase(vectorRocket.begin() + n);
        }

        void logic(CWall &wall) {
            vector<CBrick> vectorBrick = wall.getWall();
            for (int i = 0; i < vectorRocket.size(); i++) {
                if (isCollisionWall(vectorRocket[i].getTriangle(), wall)) {
                    delRocket(i);
                }
            }
        }

        void draw(RenderWindow &window) {
            for (int i = 0; i < vectorRocket.size(); i++) {
                vectorRocket[i].move();
                vectorRocket[i].draw(window);
            }
        }
};

#endif // !LIST_ROCKET_H_