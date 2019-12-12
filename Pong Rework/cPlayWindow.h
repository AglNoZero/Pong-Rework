#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class cPlayWindow
{
private:
	int WIDTH = 800; //do rong man hinh
	int HEIGHT = 600; //do cao man hinh
	Font font_Score; //font chu cua diem
	Text text[2]; // chuoi hien thi diem nguoi choi
	Font font_Speed; //font chu cua toc do ball
	Text speed; //chuoi hien thi toc do ball
	Text namePlayer[2]; //chuoi hien thi ten nguoi choi
	Font font_name; //font chu cua ten nguoi choi
public:
	//Thiết đặt giao diện - mới
	void setPlayInterface(string name1, string name2);

	//che do 2 nguoi choi
	void playGameTwoPlayer(vector<string>& kq, string name1, string name2, RenderWindow& window);//hien thi man hinh choi game, xu li qua trinh choi game
																 //input: name1, name2 la ten cua 2 nguoi choi
																//output: ten va diem cua nguoi chien thang

	//che do 1 nguoi choi
	void playGameOnePlayer(vector<string>& kq, string name, RenderWindow& window); // hien thi man hinh choi game, xu li qua trinh choi game
													//input: name la ten cua nguoi choi
												  //output: ten va diem cua nguoi chien thang

	//Giao diện kết thúc - chiến thắng
	Text* setWinnerInterface(vector<string> name);

	//hien thi man hinh ket thuc game, in ra ten nguoi chien thang
	void Winer(vector <string> name);//input: vector <string> name la ten va diem cua nguoi chien thang
	//output: man hinh ket thuc game, ten va diem nguoi chien thang duoc in
};