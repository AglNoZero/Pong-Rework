#include "cBeginMenu.h"

//cai dat cac thuoc tinh cua cac doi tuong trong menu
cBeginMenu::cBeginMenu()
{
	font_title.loadFromFile("simson.ttf");
	title.setCharacterSize(CharTitleSize); 
	
	title.setFillColor(Color(234, 201, 37));
	title.setString("Pong");

	title.setFont(font_title);
	title.setOutlineThickness(1);
	title.setOutlineColor(Color::Color(255, 0, 102, 200));

	title.setPosition((WIDTH - title.getGlobalBounds().width) / 2, 80);

	font.loadFromFile("BebasNeue-Regular.ttf");

	text[0].setFont(font);
	text[0].setCharacterSize(CharButtonSize);
	text[0].setFillColor(Color::Color(255, 0, 102, 200));
	text[0].setString("NEW GAME");
	text[0].setPosition((WIDTH - text[0].getGlobalBounds().width) / 2, 310);

	text[1].setFont(font);
	text[1].setCharacterSize(CharButtonSize);
	text[1].setFillColor(Color::White);
	text[1].setString("LOAD GAME");
	text[1].setPosition((WIDTH - text[1].getGlobalBounds().width) / 2, 380);

	text[2].setFont(font);
	text[2].setCharacterSize(CharButtonSize);
	text[2].setFillColor(Color::White);
	text[2].setString("HALL OF FAME");
	text[2].setPosition((WIDTH - text[2].getGlobalBounds().width) / 2, 450);

	text[3].setFont(font);
	text[3].setCharacterSize(CharButtonSize);
	text[3].setFillColor(Color::White);
	text[3].setString("EXIT");
	text[3].setPosition((WIDTH - text[3].getGlobalBounds().width) / 2, 520);
	

	selectItem = 0; //khoi tao doi tuong ban dau duoc chon la doi tuong thu 1
}

//ve menu len man hinh
void cBeginMenu::draw(RenderWindow& window)
{
	window.draw(title);
	for (int i = 0; i < OBJECTS; i++)
	{
		window.draw(text[i]);
	}
}

//thao tac di chuyen len tren trong cac lua chon
void cBeginMenu::moveUp()
{
	text[selectItem].setColor(Color::White);
	selectItem--;
	if (selectItem = -1) {
		selectItem = OBJECTS - 1;
	}
	text[selectItem].setColor(Color::Color(255, 0, 102, 200));
}

//thao tac di chuyen xuong duoi trong cac lua chon
void cBeginMenu::moveDown()
{
	text[selectItem].setColor(Color::White);
	selectItem++;
	if (selectItem == OBJECTS) {
		selectItem = 0;
	}
	text[selectItem].setColor(Color::Color(255, 0, 102, 200));
	
}

//cho biet doi tuong nao dang duoc chon
int cBeginMenu::getChoose()
{
	return selectItem;
}
