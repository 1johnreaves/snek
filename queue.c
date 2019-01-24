/*
 * File   : queue.c
 * Author : zentut.com
 * Purpose: stack header file
 */
/*
    initialize queue pointers
*/
void init(int *head, int *tail)
{
    *head = *tail = 0;
}

/*
   enqueue an element
   precondition: the queue is not full
*/
void enqueue(int *q,int *tail, int element)
{
    q[(*tail)++] = element;
}

/*
    dequeue an element
    precondition: queue is not empty
*/
int dequeue(int *q,int *head)
{
    return q[(*head)++];
}

/*
    return 1 if queue is full, otherwise return 0
*/
int full(int tail,const int size)
{
    return tail == size;
}

/*
  return 1 if the queue is empty, otherwise return 0
*/
int empty(int head, int tail)
{
    return tail == head;
}

/*
  display queue content
*/
void display(int *q,int head,int tail)
{
    int i = tail - 1;
    while(i >= head)
    {
        printf("%d ",q[i--]);
    }
    printf("\n");
}


//this is stuff I added myself
int isCollision(int x, int y, int *q, int head, int tail)
{
	//starting values to go through the whole thing then put it back
/*	int refx = dequeue(q, head);
	int refy = dequeue(q, head);
	enqueue(q, tail, refx);
	enqueue(q, tail, refy);*/

	int testx, testy;


	while(head != tail)
	{
	//	enqueue(&q, tail, testx);
	//	enqueue(&q, tail, testy);//put stuff back

		testx = dequeue(q, &head);
		testy = dequeue(q, &head);

		if(testx == x && testy == y)
		{return 1;}

	}
	return 0;
}
