#include "apple.c"


int volatile velocity = 0;

//VELOCITY will be either 1(UP) 2(DOWN) 3(LEFT) or 4(RIGHT)

void velUp()
{
velocity = 1;
}

void velDown()
{
velocity = 2;
}

void velLeft()
{
velocity = 3;
}

void velRight()
{
velocity = 4;
}

void velNeutral()
{
velocity = 0;
}


int getVel()
{
return velocity;
}



int changeX(int x, int velocity)
{

	if (velocity == 3)//left
	{
		x = (x - SCREEN_GRID_SIZE); //W;
		if(x < 0)
		{gameOver(); velocity = 0;}
	}
	if (velocity == 4)//right
	{
		x = (x + SCREEN_GRID_SIZE); //W;
		if(x > SCREEN_W)
		{gameOver(); velocity = 0;}
	}
	return x;
}

int changeY(int y, int velocity)
{
	if (velocity == 1)//up
	{
		y = (y - SCREEN_GRID_SIZE); //H;
		if(y < 0)
		{gameOver(); velocity = 0;}
	}
	if (velocity == 2)//down
	{
		y = (y + SCREEN_GRID_SIZE); //H;
		if(y > SCREEN_H)
		{gameOver(); velocity = 0;}
	}
	return y;
}
