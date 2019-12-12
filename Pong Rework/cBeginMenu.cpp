#include "cBeginMenu.h"

//cai dat cac thuoc tinh cua cac doi tuong trong menu
cBeginMenu::cBeginMenu()
{
	font_title.loadFromFile("simson.ttf");
	title.setCharacterSize(CharTitleSize); //Không hiểu tại sao lúc in ra màn hình thì chỉ còn 1 nửa
	//title.setOrigin(4*CharTitleSize/2, 0); //moi
	title.setFillColor(Color(234, 201, 37));
	title.setString("Pong");
	title.setPosition(370, 80); //Pong co 4 ki tu 
	title.setFont(font_title);
	title.setOutlineThickness(1);
	title.setOutlineColor(Color::Color(255, 0, 102, 200));

	font.loadFromFile("BebasNeue-Regular.ttf");

	text[0].setFont(font);
	text[0].setPosition(380, 355); //2 Players co 8 ki tu
	text[0].setCharacterSize(CharButtonSize);
	text[0].setFillColor(Color::Color(255, 0, 102, 200));
	text[0].setString("2 PLAYERS");

	text[1].setFont(font);
	text[1].setPosition(390, 433);
	text[1].setCharacterSize(CharButtonSize);
	text[1].setFillColor(Color::White);
	text[1].setString("1 PLAYER");

	text[2].setFont(font);
	text[2].setPosition(420, 515);
	text[2].setCharacterSize(CharButtonSize);
	text[2].setFillColor(Color::White);
	text[2].setString("EXIT");
	/*
	box[0].setPosition(400, 350);
	box[0].setFillColor(Color::Transparent);
	box[0].setSize(Vector2f(230, 55));
	box[0].setOutlineColor(Color::Green);
	box[0].setOutlineThickness(5);

	box[1].setPosition(400, 430);
	box[1].setFillColor(Color::Transparent);
	box[1].setSize(Vector2f(230, 55));
	box[1].setOutlineColor(Color::White);
	box[1].setOutlineThickness(5);

	box[2].setPosition(400, 510);
	box[2].setFillColor(Color::Transparent);
	box[2].setSize(Vector2f(230, 55));
	box[2].setOutlineColor(Color::White);
	box[2].setOutlineThickness(5);*/

	selectItem = 0; //khoi tao doi tuong ban dau duoc chon la doi tuong thu 1
}

//ve menu len man hinh
void cBeginMenu::draw(RenderWindow& window)
{
	window.draw(title);
	for (int i = 0; i < OBJECTS; i++)
	{
		//window.draw(box[i]);
		window.draw(text[i]);
	}
}

//thao tac di chuyen len tren trong cac lua chon
void cBeginMenu::moveUp()
{
	text[selectItem].setColor(Color::White);
	//box[selectItem].setOutlineColor(Color::Black);
	selectItem--;
	if (selectItem = -1) {
		selectItem = OBJECTS - 1;
	}
	text[selectItem].setColor(Color::Color(255, 0, 102, 200));
	//box[selectItem].setOutlineColor(Color::Black);
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
