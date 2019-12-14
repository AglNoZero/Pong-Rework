#include "cPlayerName.h"

//void cPlayerName::setTheTextBoxTwoPlayer()
//{
//	box1.setSize(Vector2f(400, 50));
//	box1.setPosition(Vector2f(300, 180));
//
//	box2.setSize(Vector2f(400, 50));
//	box2.setPosition(Vector2f(300, 380));
//
//	text1.setString("Name of player 1: ");
//	text1.setFont(font);
//	text1.setPosition(Vector2f(100, 80));
//	text1.setCharacterSize(40);
//
//	text2.setString("Name of player 2: ");
//	text2.setFont(font);
//	text2.setPosition(Vector2f(100, 280));
//	text2.setCharacterSize(40);
//
//	font.loadFromFile("Cucho Bold.otf");
//
//	textbox1.setTextBox(35, Color::Blue, true);
//	textbox1.setFont(font);
//	textbox1.setLimit(true, 20);
//	textbox1.setPosition(Vector2f(310, 185));
//
//	textbox2.setTextBox(35, Color::Blue, true);
//	textbox2.setFont(font);
//	textbox2.setLimit(true, 15);
//	textbox2.setPosition(Vector2f(310, 385));
//}

cPlayerName::cPlayerName()
{
	//Thiết đặt điểm
	scoreFont.loadFromFile("Fonts/simson.ttf");
	playerScore.setString("Score: 0");
	playerScore.setFont(scoreFont);
	playerScore.setCharacterSize(60);
	playerScore.setColor(Color(234, 201, 37));
	playerScore.setPosition((WIDTH - playerScore.getGlobalBounds().width)/2, 20);

	//Thiết đặt tiêu đề của text box
	font.loadFromFile("Fonts/BebasNeue-Regular.ttf");
	text.setString("Type your name here: ");
	text.setFont(font);
	text.setCharacterSize(40);
	text.setColor(Color::Color(255, 0, 102, 200));
	text.setPosition((WIDTH - text.getGlobalBounds().width) / 2, 300);

	//Thiết đặt khung text box
	box.setFillColor(Color::Color(255, 126, 0, 100));
	box.setSize(Vector2f(WIDTH/2, HEIGHT/12));
	box.setPosition((WIDTH - box.getGlobalBounds().width)/2, 350);

	//Thiết đặt text động được đặt trong text box (có thể thêm xóa sửa)
	dynamicText.setDynamicText(35, Color::Color(255, 126, 0, 200), true);
	dynamicText.setFont(font);
	dynamicText.setLimit(true, 20);
	dynamicText.setPosition({ box.getPosition().x + 10, box.getPosition().y });

	//Thiết đặt nút bấm
	button.setButton("SAVE NAME", { 200,80 }, 30, Color::Color(255, 0, 102, 200), Color::Black);
	button.setFont(font);
	button.setPosition({ (WIDTH - button.getGlobalBounds().width) / 2, HEIGHT - button.getGlobalBounds().height - 20 }); //Cấm xóa dấu {}, xóa đấm
}

void cPlayerName::setScore(int score)
{
	string temp = to_string(score); //C++ 11
	playerScore.setString("Score: " + temp);
}

void cPlayerName::setTheButtonPlay()
{
	button.setButton("SAVE NAME", { 200,80 }, 30, Color::Color(255, 0, 102, 200), Color::Black);
	button.setFont(font);
	button.setPosition({ (WIDTH - button.getGlobalBounds().width) / 2, HEIGHT - button.getGlobalBounds().height - 20}); //Cấm xóa dấu {}, xóa đấm
}

//void cPlayerName::fillNameTwoPlayer(string& namePlayer1, string& namePlayer2, RenderWindow& window)
//{
//	window.clear();
//	texture.loadFromFile("39607.jpg");
//	Sprite sprite(texture);
//	sprite.scale(0.5, 0.5);
//
//	setTheTextBoxTwoPlayer();
//	setTheButtonPlay();
//
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			switch (event.type)
//			{
//			case Event::Closed:
//				window.close();
//			case Event::TextEntered:
//				if (textbox1.getLimit() != 0) //neu gioi han so khi tu khac 0 thi cho phep nhap vao textbox1, nguoc lai chuyen sang nhap textbox2 
//				{
//					textbox1.typedOn(event);
//				}
//				else
//				{
//					textbox2.typedOn(event);
//				}
//
//			case Event::MouseMoved:
//				if (button.isMouseOver(window))
//				{
//					button.setBackColor(Color::Blue); //chuyen mau button khi con tro chuot dang trong pham vi button
//				}
//				else
//				{
//					button.setBackColor(Color::Green);
//				}
//				break;
//
//			case Event::MouseButtonPressed:
//				if (button.isMouseOver(window))
//				{
//					return; //neu nguoi choi ckick vao button thi tat man hinh nhap ten de chuyen sang man hinh choi game
//				}
//				break;
//
//			}
//		}
//		window.clear();
//		window.draw(sprite);
//
//		window.draw(text1);
//		window.draw(text2);
//
//		window.draw(box1);
//		window.draw(box2);
//
//		textbox1.draw(window);
//		textbox2.draw(window);
//		button.draw(window);
//		window.display();
//	}
//
//	textbox1.getText();
//	namePlayer1 = textbox1.getText();
//	namePlayer2 = textbox2.getText();
//}


void cPlayerName::display(string& namePlayer, int score, RenderWindow& window)
{
	window.clear();
	if (score <= 500) { texture.loadFromFile("Backgrounds/End game.jpg"); }
	else {
		texture.loadFromFile("Backgrounds/Good end.jpg");
	}

	Sprite sprite(texture);

	setScore(score);
	playerScore.setPosition((WIDTH - playerScore.getGlobalBounds().width) / 2, 20);

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
				if (dynamicText.getLimit() != 0)
				{
					dynamicText.typedOn(event);
				}
			case Event::MouseMoved:
				if (button.isMouseOver(window))
				{
					button.setBackColor(Color::Color(255, 126, 0, 200)); //1 loại màu cam
				}
				else
				{
					button.setBackColor(Color::Color(255, 0, 102, 200)); //1 loại màu hồng
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

		window.draw(playerScore);

		window.draw(text);

		window.draw(box);

		dynamicText.draw(window);

		button.draw(window);
		window.display();
	}
	namePlayer = dynamicText.getText();
}