#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Header.h"

#define WIDTH 900
#define HEIGHT 600

// This is where our game starts from
int main()
{

	//Thêm background
	Texture background;
	background.loadFromFile("2635205 - resize 900x600.jpg");
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

							}
							//Load game
							case 1: {

							}
							//Hall of fame
							case 2: {


							}
							//Exit
							case 3: {

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