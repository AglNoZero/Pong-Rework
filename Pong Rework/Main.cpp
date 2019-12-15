#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Header.h"

#define WIDTH 900
#define HEIGHT 600

void play();
// This is where our game starts from
int main()
{

	//Thêm background
	Texture background;
	background.loadFromFile("Backgrounds/2635205 - resize 900x600.jpg");
	Sprite Background(background);

	//Kết thúc code mới

	//Code cũ
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game"); //dau tien chuong trinh hien thi menu mo dau game

	cBeginMenu begin;

	Text a;

	Event event;

	if (window.isOpen())
	{
		while (window.isOpen())
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed) //neu co ai do nhan dau tat tren man hinh thi chuong trinh ket thuc
				{
					window.close();
				}
				//di chuyen giua cac lua chon trong menu mo dau game
				else if (event.type == Event::KeyReleased)
				{
					if (event.key.code == Keyboard::Up)
					{
						begin.moveUp();
					}
					else if (event.key.code == Keyboard::Down)
					{
						begin.moveDown();
					}
					//khi nguoi choi da chon 1 trong cac lua chon cua menu
					else if (event.key.code == Keyboard::Return)
					{
						switch (begin.getChoose()) {
							//New game
							case 0:{
								int score = 600;

								//Chơi xong thì hiện cửa sổ nhập tên và in điểm
								cPlayerName endGame;
								string namePlayer;
								endGame.display(namePlayer, score, window);

								break;
							}
							//Load game
							case 1: {

								break;
							}
							//Hall of fame
							case 2: {
								vector<string> playerName = { "Long","Phuong", "Toan", "Minh", "Luan" };
								vector<int> playerScore = { 900,800,700,600,500 };
								cHallOfFame hallOfFame(playerName, playerScore);
								hallOfFame.display(window);

								break;
							}
							//Exit
							case 3: {
								window.close();
								break;
							}
						}
					}
				}
				//neu co ai do nhan escape thi thoat chuong trinh
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					window.close();
				}
				window.clear();
				window.draw(Background);//tested - ok
				begin.draw(window);
				window.display();
			}
		}
	}
}

void play() {
	RenderWindow window(VideoMode(WIDTH_DISPLAY, HEIGHT_DISPLAY), "SFML");
	Font font;
	font.loadFromFile("Fonts/BebasNeue-Regular.ttf");
	Text text;
	text.setFont(font);
	text.setPosition(Vector2f(200, 500));
	text.setFillColor(Color::Color(255, 0, 102, 200));
	text.setCharacterSize(100);

	CPaddle *paddle = new CPaddle();
	CBall *ball = new CBall();
	CWall *wall = new CWall();

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}

		// điều khiển bóng, paddle, các va chạm cơ bản 
		ball->control(*paddle);
		ball->logic(*paddle, *wall, window);
		paddle->ifCollisionBonus(*wall);

		// xử lý thắng thua 
		if (wall->getWall().size() == 0 || paddle->getLife() == 0) {
			window.clear();

			RenderWindow win(VideoMode(WIDTH_DISPLAY, HEIGHT_DISPLAY), "SFML");
			while (win.isOpen()) {
				while (win.pollEvent(e)) {
					if (e.type == Event::Closed) {
						win.close();
					}
				}

				if (wall->getWall().size() == 0) {
					text.setString("You Won :>");
				}
				else {
					text.setString("You loser :)");
				}

				win.clear();
				win.draw(text);
				win.display();
			}
		}

		window.clear();
		wall->drawWall(window);
		ball->drawBall(ball->getBall().getPosition(), window);
		paddle->draw(window);
		window.display();
	}
}