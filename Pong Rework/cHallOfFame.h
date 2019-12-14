#pragma once

#include "Header.h"
class cHallOfFame
{
private:

	Texture background;

	Text title; //"Hall Of Fame"
	Font titleFont;

	Text player1Score; //Điểm của người chơi 1
	Text player2Score; //Điểm của người chơi 2
	Text player3Score; //Điểm của người chơi 3
	Text player4Score; //Điểm của người chơi 4
	Text player5Score; //Điểm của người chơi 5
	Font playerScoreFont; //Font cho điểm người chơi

	Text player1Name; //Tên của người chơi 1
	Text player2Name; //Tên của người chơi 2
	Text player3Name; //Tên của người chơi 3
	Text player4Name; //Tên của người chơi 4
	Text player5Name; //Tên của người chơi 5
	Font playerNameFont; //Fon cho tên người chơi

	Button backButton; //Nút back về menu
public:
	cHallOfFame(vector<string> playerName, vector<int> playerScore);
	~cHallOfFame();

	void draw(RenderWindow& window);

	void display(RenderWindow& window);

};

