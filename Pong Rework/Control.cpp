#include "Control.h"

//xu li tien trinh game tu luc bat dau dem luc ket thuc
void Control::processGame()
{
	//Thêm background
	Texture background;
	background.loadFromFile("2635205 - resize 900x600.jpg");
	Sprite Background(background);
	//Kết thúc code mới

	//Code cũ
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game"); //dau tien chuong trinh hien thi menu mo dau game

	cBeginMenu begin;

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
						switch (begin.getChoose())
						{
							//man hinh che do 2 nguoi choi
						case 0:
						{
							//tat man hinh mo dau game
							window.clear();
							cPlayerName player;
							//mo man hinh dien ten 2 nguoi choi
							string namePlayer1, namePlayer2;
							player.fillNameTwoPlayer(namePlayer1, namePlayer2, window);
							
							//choi game
							cPlayWindow playGame;
							vector <string> winer;
							playGame.playGameTwoPlayer(winer, namePlayer1, namePlayer2, window);
							//man hinh ket thuc game
							playGame.Winer(winer);
							break;
						}
						//man hinh che do 1 nguoi choi
						case 1:
						{
							//tat man hinh mo dau game
							
							//mo man hinh dien ten nguoi choi
							cPlayerName player;

							string namePlayer;
							player.fillNameOnePlayer(namePlayer, window);
							//choi game
							cPlayWindow playGame;
							vector <string> winer;
							playGame.playGameOnePlayer(winer, namePlayer, window);
							//man hinh ket thu game
							playGame.Winer(winer);
							break;
						}
						//neu chon chuc nang exit thi dong cua so chuong trinh
						case 2:
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