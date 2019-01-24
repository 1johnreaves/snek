#define NULL ( (void *) 0)

struct node
{
	int x;
	int y;
	struct node * pNext;
	//struct node * pPrev;

};

int getX(struct node * sample)
{return sample->x;}

int getY(struct node * sample)
{return sample->y;}

struct node * getNext(struct node * sample)
{return sample->pNext;}

//struct node * getPrev(struct node * sample)
//{return sample->pPrev;}



//================== other code ==========================


int ex = 0;
int ey = 0;

struct node firstnode = {&ex, &ey, NULL, NULL};

struct node * pHead = &firstnode;
struct node * pTail;

int tailwait = 0;


void pushElimVals(int x, int y)
{
	struct node newnode = {x, y, pHead, NULL};

	if(pHead->pNext == NULL)
	{
	pHead->pNext = &newnode;
	pTail = &newnode;
	}
	else
	{
	pTail->pNext = &newnode;
	pTail = &newnode;
	}



	if(tailwait==0)
	{
	struct node temp = *pHead;
	pHead = pHead->pNext;

	ex = temp.x;
	ey = temp.y;
	}
	else
	{
	tailwait -= 1;
	}
	
}


int getElimX()
{return ex;}

int getElimY()
{return ey;}

void addTail(int add)
{tailwait += add;}
