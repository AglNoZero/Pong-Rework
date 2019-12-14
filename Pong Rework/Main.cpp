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

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game"); //dau tien chuong trinh hien thi menu mo dau game

	cBeginMenu begin;

	Text a;

	Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) //neu co ai do nhan dau tat tren man hinh thi chuong trinh ket thuc
			{
				window.close();
			}
			//di chuyen giua cac lua chon trong menu mo dau game
			else if (event.type == Event::KeyPressed)
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
			else if (event.type == Event::MouseMoved) {

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

void play() {
	//Chờ bảo bảo
}