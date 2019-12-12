#pragma once 
#include <SFML/Graphics.hpp>
#include "Header.h"
using namespace std;
using namespace sf;

class Control
{
private:
	int WIDTH = 900; //do rong man hinh
	int HEIGHT = 600; //do cao man hinh

public:
	void processGame(); //xu li tien trinh game tu luc bat dau den luc ket thuc, output: man hinh bat dau, man hinh nhap ten, man hinh choi game, man hinh ket thuc
};