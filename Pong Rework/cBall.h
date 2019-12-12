#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class cPaddle;
class cBall
{
private:
	Vector2f position;// vi tri cua ball
	CircleShape ballShape; //ve ball co dang hinh tron
	float vx = 0.1; //van toc theo chieu x
	float vy = 0.1; //van toc theo chieu y
	int score[2] = { 0,0 }; //diem cua hai nguoi choi
	int radius = 10; //ban kinh ball
public:
	cBall(float initX, float initY); //constructor

	//lay cac thong so private cua class
	FloatRect getPosition();//output: vi tri toa do cua ball

	CircleShape getShape(); //output: hinh dang cua ball

	float getvx(); //output: van toc vx cua ball

	float getvy(); //output: van toc vy cua ball

	void setSpeed(); //tinh toan va cai dat toc do cho ball sau moi lan ball cham paddle, output: vx va vy da duoc tang len

	//Xet cac truong hop va cham cua ball
	void hitSides();//xet truong hop ball cham 2 canh, output: ball da duoc chuyen huong

	void hitPaddle1();//xet truong hop ball cham paddle1, output: ball da duoc chuyen huong, cong 1 diem cho player2

	void hitPaddle2();//xet truong hop ball cham paddle2, output: ball da duoc chuyen huong, cong 1 diem cho player1
	
	void hitTopOrBottom();//xet truong hop paddle khonng hung duoc ball, output: ball quay lai vi tri bat dau

	void updatePosition(); //cap nhat lai vi tri cua ball, output: vi tri toa do cua ball da duoc cap nhat

	int move(int WIDTH, int HEIGH, cPaddle paddle1, cPaddle paddle2);// xet cac truong hop va cham cua ball va tra ve ket qua thang thua
	                                                                //input: WIDTH (chieu rong man hinh), HEIGHT (chieu cao man hinh), paddle1, paddle2 (hai thanh paddle cua nguoi choi)
																	//output: ball da duoc chuyen huong, tra ve 1 neu player1 thang, ve 2 neu player2 thang, ve 0 neu khong ai thang
	int getScorePlayer1();//output: diem cua nguoi choi thu 1
	int getScorePalyer2();//output: diem cua nguoi choi thu 2

	void setScorePlayer1(int newScore);
	void setScorePlayer2(int newScore);
};
