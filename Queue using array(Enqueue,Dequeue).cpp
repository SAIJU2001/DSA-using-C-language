#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int size;
	int f;
	int r;
	int *arr;
};

int is_empty(struct queue *q)
{
	if(q->f==q->r)
	{
		printf("Queue underflow\n");
		return 1;
	}
	else
	return 0;
}

int is_full(struct queue *q)
{
	if(q->r==q->size-1)
	{
		printf("Queue overflow\n");
		return 1;
	}
	else
	return 0;
}

void enqueue(struct queue *q,int val)
{
	if(is_full(q))
	printf("You cannot enqueue the value %d\n",val);
	else
	{
		q->r++;
		q->arr[q->r]=val;
		printf("Your value is sucessfully enqueue\n");
	}
}
void dequeue(struct queue *q)
{
	if(is_empty(q))
	printf("You cannot enqueue the value \n");
	else
	{
		q->f++;
		int a=q->arr[q->f];
		printf("the value %d is dequeue from this queue\n",a);
	}
}


int main()
{
	int n;
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
	q->size=10;
	q->f=q->r=-1;
	q->arr=(int*)malloc(q->size*sizeof(int));
	do{
		printf("\nChoose the option :\n");
		printf("For enque operation press 1\nFor dequeue operation press 2\n");
		printf("For Check wheather the queue is empty or not Press 3\nFor Check wheather the queue is Full or not Press 4\n");
		printf("For exit press 0\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1 :
				{
					int l;
					printf("press the inserted value\n");
					scanf("%d",&l);
					enqueue(q,l);
				}
				break;
			case 2 :
				{
					dequeue(q);	
				}
				break;
			case 0 :
				{
					printf("Program Terminated\n");	
				}
				break;
			case 3 :
				{
					is_empty(q);	
				}
				break;
			case 4 :
				{
					is_full(q);	
				}
				break;		
			default :
					printf("Please choose the correct option\n");	
					break;
		}
	}while(n!=0);
printf("\nThank you for using my Queue\n");
printf("\n Designed and created by SAIKAT");
	
return 0;
}

