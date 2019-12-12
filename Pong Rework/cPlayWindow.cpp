#include "cPlayWindow.h"

void cPlayWindow::setPlayInterface(string name1, string name2)
{
	font_Score.loadFromFile("Facon.ttf");
	text[0].setCharacterSize(50);
	text[0].setFillColor(Color(238, 238, 5));
	text[0].setOutlineColor(Color::Red);
	text[0].setOutlineThickness(-5);
	text[0].setPosition(200, 50);
	text[0].setFont(font_Score);

	text[1].setCharacterSize(50);
	text[1].setFillColor(Color(238, 238, 5));
	text[1].setOutlineColor(Color::Red);
	text[1].setOutlineThickness(-5);
	text[1].setPosition(700, 50);
	text[1].setFont(font_Score);

	font_Speed.loadFromFile("BABYK___.TTF");
	speed.setFont(font_Speed);
	speed.setFillColor(Color(150, 20, 150));
	speed.setOutlineColor(Color(150, 150, 200));
	speed.setOutlineThickness(2);
	speed.setPosition(300, 650);

	font_name.loadFromFile("Machinegun.ttf");

	namePlayer[0].setCharacterSize(20);
	namePlayer[0].setPosition(250, 30);
	namePlayer[0].setString(name1);
	namePlayer[0].setFont(font_name);


	namePlayer[1].setCharacterSize(20);
	namePlayer[1].setPosition(700, 30);
	namePlayer[1].setString(name2);
	namePlayer[1].setFont(font_name);
}

//tra ve ten va so diem cua nguoi chien thang
void cPlayWindow::playGameTwoPlayer(vector<string>& kq, string name1, string name2, RenderWindow& window)
{
	window.clear();
	cBall ball(400, 300);

	Event event;

	cPaddle paddle1(10, HEIGHT / 2);
	cPaddle paddle2(WIDTH - 20, HEIGHT / 2);

	
	setPlayInterface(name1, name2);

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close(); //neu bam dau tat tren man hinh thi cua so tat
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			// move up...
			paddle2.moveUp(0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			// move down...
			paddle2.moveDown(HEIGHT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			// quit...
			// Someone closed the window- bye
			window.close();
		}
		else if (Keyboard::isKeyPressed(Keyboard::W))
		{
			// move up
			paddle1.moveUp(0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			// move down
			paddle1.moveDown(HEIGHT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::P)) {
			while (window.pollEvent(event))
			{
				if (event.type == Event::EventType::KeyPressed)
				{
					break;
				}
			}
		}

		int score1 = ball.getScorePlayer1();
		int score2 = ball.getScorePalyer2();

		string scorePlayer1 = to_string(score1);
		string scorePlayer2 = to_string(score2);

		text[0].setString(scorePlayer1);
		text[1].setString(scorePlayer2);

		int Win = ball.move(WIDTH, HEIGHT, paddle1, paddle2);
		ball.updatePosition();

		paddle1.update();
		paddle2.update();

		window.clear(Color::Black);

		window.draw(text[0]);
		window.draw(text[1]);

		window.draw(paddle1.getShape());
		window.draw(paddle2.getShape());

		string Speed = to_string(fabs(ball.getvx()));
		speed.setString("SPEED: " + Speed);
		window.draw(speed);

		window.draw(ball.getShape());

		window.draw(namePlayer[0]);
		window.draw(namePlayer[1]);
		window.display();
		if (Win == 1)
		{
			window.close();
			kq.push_back(name1);
			kq.push_back("Score: " + scorePlayer1);
		}
		else if (Win == 2)
		{
			window.close();
			kq.push_back(name2);
			kq.push_back("Score: " + scorePlayer2);
		}
	}
}

//tra ve ten va so diem cua nguoi chien thang
void cPlayWindow::playGameOnePlayer(vector<string>& kq, string name, RenderWindow& window)
{
	window.clear();
	cBall ball(400, 300);

	Event event;

	cPaddle paddle1(10, HEIGHT / 2);

	cPaddle paddle2(WIDTH - 20, HEIGHT / 2);

	setPlayInterface("Computer", name);

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close(); //neu bam dau tat tren man hinh thi cua so tat
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			// move up paddle
			paddle2.moveUp(0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			// move down paddle
			paddle2.moveDown(HEIGHT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			//khi co ai do nhan phim ESC thi tat man hinh
			window.close();
		}
		else if (Keyboard::isKeyPressed(Keyboard::P)) { //Nhấn P thì game pause, nhấn các phím khác để tiếp tục
			while (window.waitEvent(event))
			{
				if (event.type == Event::EventType::KeyPressed)
				{
					break;
				}
			}
		}

		//lay diem cua nguoi choi
		int score1 = ball.getScorePlayer1();
		int score2 = ball.getScorePalyer2();

		string scorePlayer1 = to_string(score1);
		string scorePlayer2 = to_string(score2);

		text[0].setString(scorePlayer1);
		text[1].setString(scorePlayer2);

		string Speed = to_string(fabs(ball.getvx()));
		speed.setString("SPEED: " + Speed);
		

		int Win = ball.move(WIDTH, HEIGHT, paddle1, paddle2);
		ball.updatePosition();

		paddle1.autoMove(0, HEIGHT, ball);

		paddle1.update();
		paddle2.update();

		//Tương tác item ở đây
		

		//Kết thúc tương tác item 

		//Hiển thị
		window.clear(Color::Black);

		window.draw(text[0]);
		window.draw(text[1]);

		window.draw(paddle1.getShape());
		window.draw(paddle2.getShape());

		window.draw(namePlayer[1]);

		window.draw(speed);

		window.draw(ball.getShape());


		window.display();
		//Kiểm tra điều kiện

		if (Win == 1)
		{
			window.close();
			kq.push_back("The Computer");
			kq.push_back("Score: " + scorePlayer1);
		}
		else if (Win == 2)
		{
			window.close();
			kq.push_back(name);
			kq.push_back("Score: " + scorePlayer2);
		}
	}
	
}

Text* cPlayWindow::setWinnerInterface(vector<string> name)//trash
{
	Font font;
	font.loadFromFile("BARBATRI.TTF");

	Text* winUI = new Text[5];

	winUI[0].setCharacterSize(50);
	winUI[0].setFont(font);
	winUI[0].setFillColor(Color(223, 0, 41));
	winUI[0].setString("THE WINER IS");
	winUI[0].setPosition(370, 20);

	font.loadFromFile("Rainbow Colors - TTF.ttf");
	winUI[1].setCharacterSize(100);
	winUI[1].setFont(font);
	winUI[1].setFillColor(Color(223, 0, 41));
	winUI[1].setOutlineColor(Color(12, 178, 192));
	winUI[1].setOutlineThickness(10);
	winUI[1].setString(name[0]);
	winUI[1].setPosition(WIDTH / 2 - winUI[1].getLocalBounds().width / 2, 150);

	winUI[2].setCharacterSize(30);
	winUI[2].setFont(font);
	winUI[2].setFillColor(Color(223, 0, 41));
	winUI[2].setOutlineColor(Color(12, 178, 192));
	winUI[2].setOutlineThickness(10);
	winUI[2].setString(name[1]);
	winUI[2].setPosition(700, 350);

	font.loadFromFile("Cucho Bold.otf");
	winUI[3].setCharacterSize(30);
	winUI[3].setFont(font);
	winUI[3].setFillColor(Color(9, 249, 20));
	winUI[3].setString("Press Enter to replay!");
	winUI[3].setPosition(350, 420);

	winUI[4].setCharacterSize(30);
	winUI[4].setFont(font);
	winUI[4].setFillColor(Color(9, 249, 20));
	winUI[4].setString("Press ESC to quit the game!");
	winUI[4].setPosition(320, 490);
	return winUI;
}

//hien thi man hinh ket thuc game va in ten, diem cua nguoi chien thang
void cPlayWindow::Winer(vector <string> name)
{
	Text* winUI = setWinnerInterface(name);

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");

	Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case Keyboard::Escape:
				{
					window.close();
					break;
				}
				case Keyboard::Return:
				{
					window.close();
					Control starGame;
					starGame.processGame();
				}
				}

			}
		}
		//Vẽ ra màn hình cái gì đó ở đây
		window.clear();
		for (int i = 0; i < 5; i++) {
			window.draw(winUI[i]);
		}

		window.display();
	}
}
