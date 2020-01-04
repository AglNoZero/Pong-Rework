#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Header.h"
#include <Windows.h>

#define WIDTH 900
#define HEIGHT 600

void play(int& score, RenderWindow& window);
void sort(vector<string> &tenNguoiChoi, vector<int> &diemNguoiChoi) {
	for (int i = 0; i < diemNguoiChoi.size() - 1; i++) {
		for (int j = i + 1; j < diemNguoiChoi.size(); j++) {
			if (diemNguoiChoi[i] < diemNguoiChoi[j]) {
				int temp = diemNguoiChoi[i];
				diemNguoiChoi[i] = diemNguoiChoi[j];
				diemNguoiChoi[j] = temp;

				string str = tenNguoiChoi[i];
				tenNguoiChoi[i] = tenNguoiChoi[j];
				tenNguoiChoi[j] = str;
			}
		}
	}
}

// This is where our game starts from
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,int nShowCmd)
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

	vector<string> playerName;
	vector<int> playerScore;
	CFile::readHallOfFame(playerName, playerScore);
	CFile::createFakeData(playerName, playerScore);

	if (window.isOpen())
	{
		while (window.isOpen())
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed) //neu co ai do nhan dau tat tren man hinh thi chuong trinh ket thuc
				{
					sort(playerName, playerScore);
					if (playerName.size() > 5) {
						for (int i = 0; i < 5; i++) {
							playerName.pop_back();
							playerScore.pop_back();
						}
					}
					CFile::writeHallOfFame(playerName, playerScore);
					window.close();
				}
				//di chuyen giua cac lua chon trong menu mo dau game
				else if (event.type == Event::KeyReleased)
				{
					if (event.key.code == Keyboard::Up)
					{
						begin.moveUp();
						cout << "Up\n";
					}
					else if (event.key.code == Keyboard::Down)
					{
						begin.moveDown();
						cout << "Down\n";
					}
					//khi nguoi choi da chon 1 trong cac lua chon cua menu
					else if (event.key.code == Keyboard::Return)
					{
						switch (begin.getChoose()) {
							//Nút bị ẩn, 100% sẽ không chạy vào case này nếu không sửa code trong cBeginMenu, hàm moveUp, moveDown, construtor
							case 0:{
								int score = 0;
								play(score, window);
								cPlayerName endGame;
								string namePlayer;
								endGame.display(namePlayer, score, window);
								playerName.push_back(namePlayer);
								playerScore.push_back(score);
								
								break;
							}
							//New game
							case 1: {
								int score = 0;
								play(score, window);
								cPlayerName endGame;
								string namePlayer;
								endGame.display(namePlayer, score, window);
								if (namePlayer.empty()) {
									namePlayer = "-";
								}
								playerName.push_back(namePlayer);
								playerScore.push_back(score);
								break;
							}
							//Hall of fame
							case 2: {

								//Gọi hàm sort
								sort(playerName, playerScore);
								//hết sort
								cHallOfFame hallOfFame(playerName, playerScore);
								hallOfFame.display(window);

								break;
							}
							//Exit
							case 3: {
								sort(playerName, playerScore);
								if (playerName.size() > 5) {
									for (int i = 0; i < 5; i++) {
										playerName.pop_back();
										playerScore.pop_back();
									}
								}
								CFile::writeHallOfFame(playerName, playerScore);
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

void play(int& score, RenderWindow& window) {

	Texture background;
	background.loadFromFile("Backgrounds/Hall of fame.jpg");
	Sprite Background;
	Background.setTexture(background);

	Clock clock;
	const float FPS = 120.0f;    //The desired FPS. (The number of updates each second).
	bool redraw = true;           //Do I redraw everything on the screen?

	CPaddle *paddle = new CPaddle();
	CBall *ball = new CBall();
	CWall *wall = new CWall();
	CControl *Control = new CControl();

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}

		//Wait until 1/120th of a second has passed, then update everything.
		if (clock.getElapsedTime().asSeconds() >= 1.0f / (FPS)) {
			redraw = true; //We're ready to redraw everything

			// điều khiển bóng, paddle, các va chạm cơ bản 
			if (paddle->getAutoRun() == false) {
				Control->control(*paddle, *ball, *wall);
			}
			else {
				ball->autoRun(*paddle);
				Control->control(*paddle, *ball, *wall);
			}
			ball->logic(*paddle, *wall);
			paddle->ifCollisionBonus(*wall);
			

			// xử lý thắng thua 
			if (wall->getWall().size() == 0 || paddle->getLife() == 0) {
			// if (false) {
				window.clear();
				window.draw(Background);
				wall->drawWall(window);
				ball->drawBall(ball->getBall().getPosition(), window);
				paddle->draw(window, *wall);
				window.display();

				Time t = seconds(1.0);
				sleep(t);

				score = paddle->getScore();
				return;
			}
			clock.restart();
		}
		// Sleep until next 1/120th of a second comes around 
		else {
			Time sleepTime = seconds((1.0f / FPS) - clock.getElapsedTime().asSeconds());
			sleep(sleepTime);
		}

		if (redraw) {
			window.clear();
			window.draw(Background);
			wall->drawWall(window);
			ball->drawBall(ball->getBall().getPosition(), window);
			paddle->draw(window, *wall);
			window.display();
			redraw = false;
		}
	}
}