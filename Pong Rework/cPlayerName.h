#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class cPlayerName
{
private:
	//che do 2 nguoi choi 

	RectangleShape box1; //khung cua textbox1
	RectangleShape box2; //khung cua textbox2
	Text text1; //tieu de textbox1
	Text text2; //tieu de textbox2
	TextBox textbox1; //noi nhap ten nguoi choi thu nhat
	TextBox textbox2; //noi nhap ten nguoi choi thu hai


	//che do 1 nguoi choi
	RectangleShape box; //khung cua textbox
	Text text; //tieu de cua textbox
	TextBox textbox; //noi nhap ten nguoi choi

	Button button; //nut de bat dau choi game
	Texture texture; //hinh nen cua man hinh nhap ten
	Font font; //font chu cua cac textbox

public:

	cPlayerName();

	void setTheButtonPlay();// output: cac thuoc tinh cua play button duoc thiet lap

	//che do 2 nguoi choi
	void setTheTextBoxTwoPlayer();//output: cac thuoc tinh cua man hinh nhap ten duoc thiet lap

	void fillNameTwoPlayer(string& namePlayer1, string& namePlayer2, RenderWindow& window); //hien thi cua so man hinh nhap ten, cho nguoi choi nhap ten, ouput: tra ve ten cua 2 nguoi choi

	//che do 1 nguoi choi
	void setTheTextBoxOnePlayer();//output: cac thuoc tinh cua play button duoc thiet lap

	void fillNameOnePlayer(string& namePlayer, RenderWindow& window);//hien thi cua so man hinh nhap ten, cho nguoi choi nhap ten, ouput: tra ve ten cua nguoi choi
};