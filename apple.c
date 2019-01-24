#define SCREENBUFFER        ((volatile u16*)0x06000000)
#define SCREEN_W            240
#define SCREEN_H            160
#define SCREEN_GRID_SIZE	10

int applex, appley, i;
int over = 0;

//draws rectangle from L2R, top to bottom
void drawRect(int left, int top, int width, int height, u16 clr)
{
	for(int y=0; y < height; y++){
	for(int x=0; x < width; x++){
	SCREENBUFFER[(top + y) * SCREEN_W + (left + x)] = clr;	
	}}
}

void apple()
{
	applex = rand() % SCREEN_W % SCREEN_GRID_SIZE;
	appley = rand() % SCREEN_H % SCREEN_GRID_SIZE;
	applex *= SCREEN_GRID_SIZE;
	appley *= SCREEN_GRID_SIZE;
	i = (appley * SCREEN_W) + applex;
	if(SCREENBUFFER[i] != 0x0000)
	{apple();}
	else{drawRect(applex, appley, SCREEN_GRID_SIZE, SCREEN_GRID_SIZE, 0x0F00);}

}

int appleX() {return applex;}

int appleY() {return appley;}

int applecollision(int x, int y)
{
	return((applex == x) && (appley == y));
}




void gameOver()
{
	for (int i = 0; i < SCREEN_W * SCREEN_H; ++i)
    {
    	SCREENBUFFER[i] = 0x000F; //fills screen with color
    }
	over = 1;
}
