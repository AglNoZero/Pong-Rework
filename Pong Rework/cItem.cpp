#include "Header.h"

cItem::cItem(float initX, float initY, int type)
{//Truyền đối số là vị trí item với x = WIDTH/2; y random trong khoảng 0 -->HEIGHT; type random từ 1-->11
	
	position.x = initX;
	position.y = initY;
	this->type = type;
	goToPlayer = 1 + (rand() % 2);
	if (goToPlayer == 1) {
		itemShape.setRotation(90);
	}
	else {
		itemShape.setRotation(-90);
	}
	itemShape.setRadius(radius);
	itemShape.setPosition(position);
	
}

void cItem::loadTextureFromTextureArray(Texture* textureArr)
{
	switch (type) {
	case 0: {
		//do nothing
		itemShape.setFillColor(Color::Transparent);
		itemShape.setOutlineColor(Color::Transparent);
		break;
	}
	case 1: {// Dollar +1 điểm
		itemShape.setTexture(&textureArr[0]);
		break;
	}
	case 2: {// Kim cương vàng +3 điểm
		itemShape.setTexture(&textureArr[1]);
		break;
	}
	case 3: {// Kim cương đỏ +5 điểm
		itemShape.setTexture(&textureArr[2]);
		break;
	}
	case 4: {// Kim cương xanh +10 điểm
		itemShape.setTexture(&textureArr[3]);
		break;
	}
	case 5: {// Xương cá -1 điểm
		itemShape.setTexture(&textureArr[4]);
		break;
	}
	case 6: {// Bomb -10 điểm
		itemShape.setTexture(&textureArr[5]);
		break;
	}
	case 7: {// Mở rộng
		itemShape.setTexture(&textureArr[6]);
		break;
	}
	case 8: {// Thu nhỏ
		itemShape.setTexture(&textureArr[7]);
		break;
	}
	case 9: {// Tăng tốc
		itemShape.setTexture(&textureArr[8]);
		break;
	}
	case 10: {// Giảm tốc
		itemShape.setTexture(&textureArr[9]);
		break;
	}
	case 11: {// Đóng băng
		itemShape.setTexture(&textureArr[10]);
		break;
	}

	}
}


FloatRect cItem::getPosition()
{
	return itemShape.getGlobalBounds();
}

CircleShape cItem::getShape()
{
	return itemShape;
}

void cItem::updatePosition()
{
	position.x = position.x + vx;
	itemShape.setPosition(position);
}

void cItem::itemInteraction(cBall & ball, cPaddle & paddle)
{
	switch (type) {
	case 0:{
			//do nothing
			break;
		}
	case 1: {// Dollar +1 điểm
		int newScore = ball.getScorePlayer1() + 1;
		ball.setScorePlayer1(newScore);
		break;
	}
	case 2: {// Kim cương vàng +3 điểm
		int newScore = ball.getScorePlayer1() + 3;
		ball.setScorePlayer1(newScore);
		break;
	}
	case 3: {// Kim cương đỏ +5 điểm
		int newScore = ball.getScorePlayer1() + 5;
		ball.setScorePlayer1(newScore);
		break;
	}
	case 4: {// Kim cương xanh +10 điểm
		int newScore = ball.getScorePlayer1() + 10;
		ball.setScorePlayer1(newScore);
		break;
	}
	case 5: {// Xương cá -1 điểm
		int newScore = ball.getScorePlayer1() - 1;
		ball.setScorePlayer1(newScore);
		break;
	}
	case 6: {// Bomb -10 điểm
		int newScore = ball.getScorePlayer1() - 10;
		ball.setScorePlayer1(newScore);
		break;
	}
	case 7: {// Mở rộng
		paddle.expand();
	}
	case 8: {// Thu nhỏ
		paddle.minimize();
	}
	case 9: {// Tăng tốc
		paddle.speedUp();
	}
	case 10: {// Giảm tốc
		paddle.speedDown();
	}
	case 11: {// Đóng băng
		paddle.freeze();
	}

	}
}

void cItem::itemsInteraction(cBall& ball, cPaddle& paddle1, cPaddle& paddle2)
{
	if (goToPlayer == 1) {//Nếu item phải trôi tới paddle1 (Trường hợp trôi tới paddle 2 thì vx đã dương sẵn, không cần đổi)
		vx = -vx; //Thì trôi thôi <(")
	}
	//Truong hop ball cham paddle 1
	if (getPosition().intersects(paddle1.getPosition()))
	{
		itemInteraction(ball, paddle1);
	}

	//Truong hop ball cham paddle 2
	if (getPosition().intersects(paddle2.getPosition()))
	{
		itemInteraction(ball, paddle2);
	}

}
