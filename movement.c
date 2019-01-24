//this file should handle all the movement-type dealios
int imax;


#include "velocity.c"

void moveAround(int x, int y, int elimx, int elimy, int velocity, u16 clr) //1=up, 2=down, 3=left, 4=right
{
	
	switch(velocity)
	{
		case 1://up

			y = changeY(y, velocity); //should wrap around y


			drawRect(x, y, SCREEN_GRID_SIZE, SCREEN_GRID_SIZE, clr);
			drawRect(elimx, elimy, SCREEN_GRID_SIZE, SCREEN_GRID_SIZE, 0x0000);

			break;
		
		case 2://down

			y = changeY(y, velocity); //should wrap around y


			drawRect(x, y, SCREEN_GRID_SIZE, SCREEN_GRID_SIZE, clr);
			drawRect(elimx, elimy, SCREEN_GRID_SIZE, SCREEN_GRID_SIZE, 0x0000);

			break;
		
		case 3://left

			x = changeX(x, velocity); //should wrap around x

			drawRect(x, y, SCREEN_GRID_SIZE, SCREEN_GRID_SIZE, clr);
			drawRect(elimx, elimy, SCREEN_GRID_SIZE, SCREEN_GRID_SIZE, 0x0000);


			break;
		
		case 4://right

			x = changeX(x, velocity); //should wrap around x

			drawRect(x, y, SCREEN_GRID_SIZE, SCREEN_GRID_SIZE, clr);
			drawRect(elimx, elimy, SCREEN_GRID_SIZE, SCREEN_GRID_SIZE, 0x0000);

			break;
		
		default:
			drawRect(x, y, SCREEN_GRID_SIZE, SCREEN_GRID_SIZE, clr);
			break;

	}
		


}

