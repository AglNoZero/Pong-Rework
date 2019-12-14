#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include <SFML/Graphics.hpp>
#include "Header.h"
using namespace sf;

#define WIDTH 900
#define HEIGHT 600

#define OBJECTS 4 //so doi tuong lua chon trong menu
#define CharTitleSize 70 //kich co chu tieu de - moi
#define CharButtonSize 40 //Kich co chu cua nut - moi

class cBeginMenu
{
private:
	int selectItem; //cho biet doi tuong nao dang duoc chon
	Font font; //font chu cua cac doi tuong
	RectangleShape box[OBJECTS]; //Khung cua cac doi tuong
	Text text[OBJECTS]; //Ten cua cac doi tuong
	Text title; //tieu de menu
	Font font_title; //font chu cua menu

public:
	cBeginMenu(); //khoi tao menu cac thuoc tinh cua menu, output: menu bat dau game duoc tao, doi tuong dau tien duoc chon

	void draw(RenderWindow& window);//ve menu len man hinh, input: man hinh ma ta ve vao, output: menu da duoc ve len man hinh window

	void moveUp();// di chuyen len tren trong menu, ouput: doi tuong o tren duoc chon

	void moveDown();//di chuyen xuong duoi trong menu, output: doi tuong o duoi duoc chon

	int getChoose();//cho biet doi tuong nao dang duoc chon, ouput: tra ve thu tu cua doi tuong duoc chon trong menu


};
