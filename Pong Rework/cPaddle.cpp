#include "cPaddle.h"

cPaddle::cPaddle(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	cPaddleShape.setSize(sf::Vector2f(150, 10));
	cPaddleShape.setPosition(position);
	cPaddleShape.setFillColor(Color(6, 232, 203));
}


FloatRect cPaddle::getPosition()
{
	return cPaddleShape.getGlobalBounds();
}

RectangleShape cPaddle::getShape()
{
	return cPaddleShape;
}

void cPaddle::moveUp(int Top)
{
	if (position.y >= Top)
	{
		position.y -= cPaddleSpeed;
	}
}

void cPaddle::moveDown(int Bot)
{

	if (position.y + getPosition().height <= Bot)
	{
		position.y += cPaddleSpeed;
	}
}

void cPaddle::moveLeft(int WIDTH)
{
	if (position.x <= WIDTH)
	{
		position.x -= cPaddleSpeed;
	}
}

void cPaddle::moveRight(int WIDTH)
{
	if (position.x <= WIDTH)
	{
		position.x += cPaddleSpeed;
	}
}


void cPaddle::update()
{
	cPaddleShape.setPosition(position);
}


void cPaddle::autoMove(int Top, int Bot, cBall ball)
{

	if (position.y + getPosition().height < ball.getPosition().top)
	{
		moveDown(Bot);
	}
	else if (position.y > ball.getPosition().top)
	{
		moveUp(Top);
	}
}

void cPaddle::expand()
{
	Vector2f temp = cPaddleShape.getSize();
	temp.x = temp.x *1.1;
	cPaddleShape.setSize(temp);
}

void cPaddle::minimize()
{
	Vector2f temp = cPaddleShape.getSize();
	temp.x = temp.x*0.9;
	cPaddleShape.setSize(temp);
}

void cPaddle::speedUp()
{
	if (cPaddleSpeed < 1) {
		cPaddleSpeed *= 1.1;
	}
}

void cPaddle::speedDown()
{
	if (cPaddleSpeed > 0.2) {
		cPaddleSpeed *= 0.9;
	}
}

void cPaddle::freeze()
{
	cPaddleSpeed = 0;
}

void cPaddle::reset()
{
	cPaddleShape.setSize(sf::Vector2f(150, 10));
	cPaddleShape.setPosition(position);
	cPaddleShape.setFillColor(Color(6, 232, 203));
	cPaddleSpeed = 0.4f;
}
