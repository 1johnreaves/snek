#include "toolbox.h"
#include "input.h"
#include "text.c"
#include "movement.c"

#include "queue.c"



int main()
{
 REG_DISPCNT = DCNT_MODE3 | DCNT_BG2; //basic videomode stuff

    for (int i = 0; i < SCREEN_W * SCREEN_H; ++i)
    {
    	SCREENBUFFER[i] = 0x0000; //fills screen with color
    }
 

int tempx = 0;
int tempy = 0;

int gameyettostart = 1;

int framerate = 0;



const int SIZE = 1000000; // queue's size 
    int head, tail, element;
    int queue[SIZE];

    

    init(&head,&tail);

int snakewait = 0;

int elimx, elimy;

 while(1)
	{
		vid_vsync();
		

		if(gameyettostart)
		{
		drawString("SNEK        Press A to start", 0x0FF0, 0, 60); //char* msg, COLOR textCol, int x, int y)
		key_poll();
		if(key_tri_fire())
		{
			gameyettostart=0;
			 for (int i = 0; i < SCREEN_W * SCREEN_H; ++i)
    				{
    					SCREENBUFFER[i] = 0x0000; //fills screen with color
    				}
			apple();
		} 
		}

		if(!over && !gameyettostart && framerate++%5==0)
		{
			key_poll();
			if (applecollision(tempx, tempy))
			{apple(); snakewait += 1;}
	
			if(key_tri_horz() > 0 && getVel() != 3)//right, not if left
			{velRight();}
				
			if(key_tri_horz() < 0 && getVel() != 4)//left, not if right
			{velLeft();}

			if(key_tri_vert() > 0 && getVel() != 1)//down, not if up
			{velDown();}
		
			if(key_tri_vert() < 0 && getVel() != 2)//up, not if down
			{velUp();}
		
			enqueue(queue, &tail, tempx);
			enqueue(queue, &tail, tempy);

			if(snakewait == 0)
			{
				elimx = dequeue(queue, &head);
				elimy = dequeue(queue, &head);
			}
			else{snakewait -= 1;}			


			moveAround(tempx, tempy, elimx, elimy, getVel(), 0xFFFF);
			tempx = changeX(tempx, getVel());
			tempy = changeY(tempy, getVel());


			if(isCollision(tempx, tempy, queue, head, tail))
			{gameOver();}

		}

 


		if(over && !gameyettostart)
		{
			
			drawString("Game Over!", 0x0000, 0, 40); //char* msg, COLOR textCol, int x, int y)
			drawString("Press A to try again", 0x0000, 0, 60);
			key_poll();
			if(key_tri_fire())
			{
				snakewait = 0;
				elimx = elimy = 0;
				over=0;
				gameyettostart=1;
				tempx = tempy = 0;
				velNeutral();
				while(!empty(head, tail))
				{dequeue(queue, &head);}
			}
		}





	}







return 0;
}
