#include "cHallOfFame.h"



cHallOfFame::cHallOfFame(vector<string> playerName, vector<int> playerScore)
{
	
	//Thiết đặt tiêu đề Hall of fame
	titleFont.loadFromFile("Fonts/simson.ttf");
	title.setString("HALL OF FAME");
	title.setFont(titleFont);
	title.setCharacterSize(80);
	title.setColor(Color(234, 201, 37));
	title.setPosition((WIDTH - title.getGlobalBounds().width) / 2, 20);

	int scorePosX = title.getPosition().x, namePosX = 450;
	playerScoreFont.loadFromFile("Fonts/Leoscar Sans Serif.ttf");
	playerNameFont.loadFromFile("Fonts/BebasNeue-Regular.ttf");
	//Thiết đặt tên và điểm người chơi 1
	player1Score.setString(to_string(playerScore[0]));
	player1Score.setFont(playerNameFont);
	player1Score.setCharacterSize(50);
	player1Score.setPosition(scorePosX, 120);

	player1Name.setString(playerName[0]);
	player1Name.setFont(playerNameFont);
	player1Name.setCharacterSize(50);
	player1Name.setPosition(namePosX, 120);

	//Thiết đặt tên và điểm người chơi 2
	player2Score.setString(to_string(playerScore[1]));
	player2Score.setFont(playerNameFont);
	player2Score.setCharacterSize(50);
	player2Score.setPosition(scorePosX, 180);

	player2Name.setString(playerName[1]);
	player2Name.setFont(playerNameFont);
	player2Name.setCharacterSize(50);
	player2Name.setPosition(namePosX, 180);

	//Thiết đặt tên và điểm người chơi 3
	player3Score.setString(to_string(playerScore[2]));
	player3Score.setFont(playerNameFont);
	player3Score.setCharacterSize(50);
	player3Score.setPosition(scorePosX, 240);

	player3Name.setString(playerName[2]);
	player3Name.setFont(playerNameFont);
	player3Name.setCharacterSize(50);
	player3Name.setPosition(namePosX, 240);

	//Thiết đặt tên và điểm người chơi 4
	player4Score.setString(to_string(playerScore[3]));
	player4Score.setFont(playerNameFont);
	player4Score.setCharacterSize(50);
	player4Score.setPosition(scorePosX, 300);

	player4Name.setString(playerName[3]);
	player4Name.setFont(playerNameFont);
	player4Name.setCharacterSize(50);
	player4Name.setPosition(namePosX, 300);

	//Thiết đặt tên và điểm người chơi 5
	player5Score.setString(to_string(playerScore[4]));
	player5Score.setFont(playerNameFont);
	player5Score.setCharacterSize(50);
	player5Score.setPosition(scorePosX, 360);

	player5Name.setString(playerName[4]);
	player5Name.setFont(playerNameFont);
	player5Name.setCharacterSize(50);
	player5Name.setPosition(namePosX, 360);

	//Thiết đặt nút backButton
	backButton.setButton("BACK TO MENU", { 200,80 }, 30, Color::Color(255, 0, 102, 200), Color::Black);
	backButton.setFont(playerNameFont);
	backButton.setPosition({ (WIDTH - backButton.getGlobalBounds().width) / 2, HEIGHT - backButton.getGlobalBounds().height - 20 }); //Cấm xóa dấu {}, xóa đấm
}


cHallOfFame::~cHallOfFame()
{
}

void cHallOfFame::draw(RenderWindow & window)
{
	window.draw(title);

	window.draw(player1Score);
	window.draw(player2Score);
	window.draw(player3Score);
	window.draw(player4Score);
	window.draw(player5Score);

	window.draw(player1Name);
	window.draw(player2Name);
	window.draw(player3Name);
	window.draw(player4Name);
	window.draw(player5Name);
}

void cHallOfFame::display(RenderWindow & window)
{
	window.clear();
	background.loadFromFile("Backgrounds/Hall of fame.jpg");

	Sprite Background(background);

	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			else if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
				return;
			}
			switch (event.type)
			{
			case Event::Closed:
				window.close();
		
			case Event::MouseMoved:
				if (backButton.isMouseOver(window))
				{
					backButton.setBackColor(Color::Color(255, 126, 0, 200)); //1 loại màu cam
				}
				else
				{
					backButton.setBackColor(Color::Color(255, 0, 102, 200)); //1 loại màu hồng
				}
				break;
			case Event::MouseButtonPressed:
				if (backButton.isMouseOver(window))
				{
					return;
				}
				break;
			}
		}
		window.clear();
		window.draw(Background);

		draw(window);
	
		backButton.draw(window);
		window.display();
	}
}
