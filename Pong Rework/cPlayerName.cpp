#include "cPlayerName.h"

void cPlayerName::setTheTextBoxTwoPlayer()
{
	box1.setSize(Vector2f(400, 50));
	box1.setPosition(Vector2f(300, 180));

	box2.setSize(Vector2f(400, 50));
	box2.setPosition(Vector2f(300, 380));

	text1.setString("Name of player 1: ");
	text1.setFont(font);
	text1.setPosition(Vector2f(100, 80));
	text1.setCharacterSize(40);

	text2.setString("Name of player 2: ");
	text2.setFont(font);
	text2.setPosition(Vector2f(100, 280));
	text2.setCharacterSize(40);

	font.loadFromFile("Cucho Bold.otf");

	textbox1.setTextBox(35, Color::Blue, true);
	textbox1.setFont(font);
	textbox1.setLimit(true, 20);
	textbox1.setPosition(Vector2f(310, 185));

	textbox2.setTextBox(35, Color::Blue, true);
	textbox2.setFont(font);
	textbox2.setLimit(true, 15);
	textbox2.setPosition(Vector2f(310, 385));
}

cPlayerName::cPlayerName()
{
	box1.setSize(Vector2f(400, 50));
	box1.setPosition(Vector2f(300, 180));

	box2.setSize(Vector2f(400, 50));
	box2.setPosition(Vector2f(300, 380));

	text1.setString("Name of player 1: ");
	text1.setFont(font);
	text1.setPosition(Vector2f(100, 80));
	text1.setCharacterSize(40);

	text2.setString("Name of player 2: ");
	text2.setFont(font);
	text2.setPosition(Vector2f(100, 280));
	text2.setCharacterSize(40);

	font.loadFromFile("Cucho Bold.otf");

	textbox1.setTextBox(35, Color::Blue, true);
	textbox1.setFont(font);
	textbox1.setLimit(true, 20);
	textbox1.setPosition(Vector2f(310, 185));

	textbox2.setTextBox(35, Color::Blue, true);
	textbox2.setFont(font);
	textbox2.setLimit(true, 15);
	textbox2.setPosition(Vector2f(310, 385));
}

void cPlayerName::setTheButtonPlay()
{
	button.setButton("PLAY NOW", { 200,80 }, 30, Color::Green, Color::Black);
	button.setFont(font);
	button.setPosition({ 400, 550 });
}

void cPlayerName::fillNameTwoPlayer(string& namePlayer1, string& namePlayer2, RenderWindow& window)
{
	window.clear();
	texture.loadFromFile("39607.jpg");
	Sprite sprite(texture);
	sprite.scale(0.5, 0.5);

	setTheTextBoxTwoPlayer();
	setTheButtonPlay();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
			case Event::TextEntered:
				if (textbox1.getLimit() != 0) //neu gioi han so khi tu khac 0 thi cho phep nhap vao textbox1, nguoc lai chuyen sang nhap textbox2 
				{
					textbox1.typedOn(event);
				}
				else
				{
					textbox2.typedOn(event);
				}

			case Event::MouseMoved:
				if (button.isMouseOver(window))
				{
					button.setBackColor(Color::Blue); //chuyen mau button khi con tro chuot dang trong pham vi button
				}
				else
				{
					button.setBackColor(Color::Green);
				}
				break;

			case Event::MouseButtonPressed:
				if (button.isMouseOver(window))
				{
					return; //neu nguoi choi ckick vao button thi tat man hinh nhap ten de chuyen sang man hinh choi game
				}
				break;

			}
		}
		window.clear();
		window.draw(sprite);

		window.draw(text1);
		window.draw(text2);

		window.draw(box1);
		window.draw(box2);

		textbox1.draw(window);
		textbox2.draw(window);
		button.draw(window);
		window.display();
	}

	textbox1.getText();
	namePlayer1 = textbox1.getText();
	namePlayer2 = textbox2.getText();
}

void cPlayerName::setTheTextBoxOnePlayer()
{
	box.setSize(Vector2f(400, 50));
	box.setPosition(Vector2f(300, 380));

	text.setString("Name of player: ");
	text.setFont(font);
	text.setPosition(Vector2f(350, 210));
	text.setCharacterSize(40);

	font.loadFromFile("Cucho Bold.otf");

	textbox.setTextBox(35, Color::Blue, true);
	textbox.setFont(font);
	textbox.setLimit(true, 15);
	textbox.setPosition(Vector2f(310, 385));
}

void cPlayerName::fillNameOnePlayer(string& namePlayer, RenderWindow& window)
{
	window.clear();
	texture.loadFromFile("39607.jpg");
	Sprite sprite(texture);

	setTheTextBoxOnePlayer();
	setTheButtonPlay();

	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
			case Event::TextEntered:
				if (textbox.getLimit() != 0)
				{
					textbox.typedOn(event);
				}
			case Event::MouseMoved:
				if (button.isMouseOver(window))
				{
					button.setBackColor(Color::Blue);
				}
				else
				{
					button.setBackColor(Color::Green);
				}
				break;
			case Event::MouseButtonPressed:
				if (button.isMouseOver(window))
				{
					return;
				}
				break;
			}
		}
		window.clear();
		window.draw(sprite);

		window.draw(text);

		window.draw(box);

		textbox.draw(window);

		button.draw(window);
		window.display();
	}
	namePlayer = textbox.getText();
}