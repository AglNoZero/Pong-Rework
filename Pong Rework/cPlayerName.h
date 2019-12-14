#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class cPlayerName
{
private:
	RectangleShape box; //khung cua textbox
	Text text; //tieu de cua textbox
	DynamicText dynamicText; //noi nhap ten nguoi choi

	Button button; //nut de bat dau choi game
	Texture texture; //hinh nen cua man hinh nhap ten
	Font font; //font chu cua cac textbox

	Font scoreFont;
	Text playerScore; //Điểm của người chơi

public:

	cPlayerName();

	void setScore(int score);

	void setTheButtonPlay();// output: cac thuoc tinh cua play button duoc thiet lap

	void fillNameOnePlayer(string& namePlayer, int playerScore, RenderWindow& window);//hien thi cua so man hinh nhap ten, cho nguoi choi nhap ten, ouput: tra ve ten cua nguoi choi
};