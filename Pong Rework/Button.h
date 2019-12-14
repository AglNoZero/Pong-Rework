#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;

class Button
{
private:
	RectangleShape button;
	Text text; //ten button
	int buttonWidth; //do rong cua button
	int buttonHeight; //do cao cua button
public:

	FloatRect getGlobalBounds(); //Lấy kích cỡ nút
	void setButton(string buttonText, Vector2f buttonSize, int charSize, Color buttonColor, Color textColor); //cai dat cac thuoc tinh ban dau cho button
	void setFont(Font& font); //cai dat font chu cho ten button, input: font chu can cai dat, output: ten button da duoc cai dat font
	void setBackColor(Color color); //cai dat mau cho button, input: mau sac can cai dat, output: button da duoc cai dat mau
	void setTextColor(Color color); //cai dat mau chu cho button, input: mau sac can cai dat cho ten button, output: ten button da duoc cai dat mau chu
	void setPosition(Vector2f point); //cai dat vi tri button, input: vi tri can cai dat cho button, output: button da duoc cai dat vi tri
	void draw(RenderWindow& window); //ve button len man hinh, input: man hinh ma ta muon ve button len do, output: button da duoc ve len cua so window truyen vao
	bool isMouseOver(RenderWindow& window); 
	bool isMouseOverText(RenderWindow& window);
	//kiem tra xem con tro chuot co dang trong pham vi button
    //input: man hinh ma ta da ve button len do, output: return true neu con tro chuot dang o trong button, nguoc lai return false
};