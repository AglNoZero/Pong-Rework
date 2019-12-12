#pragma once

#include "Header.h"
class cItem
{
private:
	Vector2f position;// vi tri cua item
	CircleShape itemShape; //ve ball co dang hinh tron
	float vx = 0.1; //van toc theo chieu x
	float vy = 0.1; //van toc theo chieu y
	int radius = 20; //ban kinh item
	int type = 0;
	int goToPlayer;
public:
	cItem(float initX, float initY, int type);

	void loadTextureFromTextureArray(Texture* textureArr);
	//lay cac thong so private cua class
	FloatRect getPosition();//output: vi tri toa do cua item

	CircleShape getShape();

	void updatePosition(); //cap nhat lai vi tri cua item

	void itemInteraction(cBall& ball, cPaddle& paddle);

	void itemsInteraction(cBall& ball, cPaddle& paddle1, cPaddle& paddle2);

	//Các bước để đưa item vào game:
	//Tạo item, vẽ item ngẫu nhiên. Cho ngẫu nhiên trôi về 1 trong 2 phía của người chơi.
	//Gọi tương tác của item

};


