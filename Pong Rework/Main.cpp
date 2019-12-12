#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Header.h"

// This is where our game starts from
int main()
{
	
	Control play;
	play.processGame();
	return 0;
	

	/*
	int width = 800, height = 600;
	renderwindow window(videomode(width, height), "ping pong game");
	cplaywindow playgame;
	string nameplayer = "meow";
	string nameplayer1 = "meow", nameplayer2 = "meo meo";
	vector <string> winer;
	playgame.playgameoneplayer(winer, nameplayer, window);
	playgame.playgametwoplayer(winer, nameplayer1, nameplayer2, window);
	*/

	/*
	cItem anItem(0,0,1);
	Texture* textureArr = new Texture[11];
	textureArr[0].loadFromFile("Items/dollar.png");
	textureArr[1].loadFromFile("Items/yellow diamond.png");
	textureArr[2].loadFromFile("Items/red diamond.png");
	textureArr[3].loadFromFile("Items/diamond.png");
	textureArr[4].loadFromFile("Items/fish bone.png");
	textureArr[5].loadFromFile("Items/bomb.png");
	textureArr[6].loadFromFile("Items/expand.png");
	textureArr[7].loadFromFile("Items/minimize.png");
	textureArr[8].loadFromFile("Items/speed up.png");
	textureArr[9].loadFromFile("Items/speed down.png");
	textureArr[10].loadFromFile("Items/frezee.png");
	anItem.loadTextureFromTextureArray(textureArr);

	RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(anItem.getShape());
	
		// Update the window
		window.display();
	}
	*/
}