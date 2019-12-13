#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class cBall;
class cPaddle
{
private:
	Vector2f position; //vi tri cua paddle
	RectangleShape cPaddleShape; //hinh dang cua paddle
	float cPaddleSpeed = .4f; //toc do cua paddle
public:

	cPaddle(float startX, float startY); //cai dat cac thuoc tinh cua paddle, input: startX va startY la toa do ta muon gan cho paddle, output: cac thuoc tinh cua paddle da duoc cai dat

	FloatRect getPosition();//ouput: vi tri cua paddle

	RectangleShape getShape();//output: hinh dang cua paddle

	void moveUp(int Top); //di chuyen paddle len tren, input: Top(canh tren cua man hinh), output: vi tri cua paddle da duoc doi len tren

	void moveDown(int Bot); //di chuyen paddle xuong duoi, input: Bot(canh duoi cua man hinh), output: vi tri cua paddle da duoc doi xuong duoi

	void moveLeft(int WIDTH);

	void moveRight(int WIDTH);

	void update(); //cap nhat vi tri paddle, output: vi tri cua paddle da duoc cap nhat

	void autoMove(int Top, int Bot, cBall ball); //cho paddle tu di chuyen
												//input: Top(canh tren man hinh), Bot (canh duoi man hinh), ball (ball duoc truyen vao)
												//output:vi tri cua paddle thay doi tu dong
	void expand(); //Tăng kích thước paddle
	void minimize();//Giảm kích thước paddle
	void speedUp(); //Tăng tốc paddle
	void speedDown(); //Tăng tốc paddle
	void freeze(); //Đóng băng paddle
	void reset(); //Reset các thông số paddle về ban đầu
};