#include "cBall.h"

//khoi tao cac thuoc tinh ban dau cho ball
cBall::cBall(float initX, float initY)
{
	position.x = initX;
	position.y = initY;
	ballShape.setRadius(10);
	ballShape.setPosition(position);
	ballShape.setFillColor(Color(77, 214, 23));
}

//lay vi tri cua ball
FloatRect cBall::getPosition()
{
	return ballShape.getGlobalBounds();
}

//lay hinh dang cua ball
CircleShape cBall::getShape()
{
	return ballShape;
}

//lay vx
float cBall::getvx()
{
	return vx;
}

//lay vy
float cBall::getvy()
{
	return vy;
}

//truong hop ball va cham voi hai canh ben
void cBall::hitSides()
{
	vy = -vy; //chuyen huong vy
}

//truong hop ball va cham voi paddle

void cBall::hitPaddle2()
{
	if (vx > 0)
	{
		setSpeed();
		vx = -vx; //chuyen huong vx
		score[1]++;
	}

}

void cBall::hitPaddle1()
{
	if (vx < 0)
	{
		setSpeed();
		vx = -vx; //chuyen huong vx
		score[0]++;
	}

}


//truong hop paddle khong hung duoc ball
void cBall::reset()
{
	//quay lai vi tri bat dau
	position.x = 550;
	position.y = 400;
	vx = 0.1;
	vy = 0.1;
	score[0] = 0;
	score[1] = 0;
}

//cap nhat lai vi tri cua ball
void cBall::updatePosition()
{
	position.x = position.x + vx;
	position.y = position.y + vy;
	ballShape.setPosition(position);
	
}

int cBall::move(int WIDTH, int HEIGHT, cPaddle paddle1, cPaddle paddle2)
{
	//Truong hop ball cham sides
	if (getPosition().top < 0)
	{
		hitSides();
	}
	if ((getPosition().top + getPosition().height) > HEIGHT)
	{
		hitSides();
	}

	//Truong hop khong hung duoc ball
	if (getPosition().left < 0) //at top
	{
		reset();
		return 2;
	}
	if (getPosition().left > WIDTH)
	{
		reset();
		return 1;
	}

	//Truong hop ball cham paddle 1
	if (getPosition().intersects(paddle1.getPosition()))
	{
		hitPaddle1();
	}

	//Truong hop ball cham paddle 2
	if (getPosition().intersects(paddle2.getPosition()))
	{
		hitPaddle2();
		
	}
	
	

	return 0;

}

//tinh toan va cai dat cho ball sau moi lan hung duoc ball
void cBall::setSpeed()
{
	if (fabs(vx) <= 0.6)
	{
		if (vx <= 0)
		{
			vx = vx - 0.02;
		}
		else if (vx >= 0)
		{
			vx = vx + 0.02;
		}

		if (vy <= 0)
		{
			vy = vy - 0.02;
		}
		else if (vy >= 0)
		{
			vy = vy + 0.02;
		}
	}

}

//lay diem cua nguoi choi thu nhat 
int cBall::getScorePlayer1()
{
	return score[0];
}

//lay diem cua nguoi choi thu hai
int cBall::getScorePalyer2()
{
	return score[1];
}

void cBall::setScorePlayer1(int newScore)
{
	score[0] = newScore;
}

void cBall::setScorePlayer2(int newScore)
{
	score[1] = newScore;
}
