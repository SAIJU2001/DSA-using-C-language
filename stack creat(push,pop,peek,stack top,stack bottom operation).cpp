#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	int *arr;
};

int is_empty(struct stack *ptr)
{
	if(ptr->top==-1)
	return 1;
	else 
	return 0;
}

int is_full(struct stack *ptr)
{	
	if(ptr->top==ptr->size-1)
	return 1;
	else
	return 0;
}

void push(struct stack *ptr,int val)
{
	if(is_full(ptr))
	printf("\nStack Overflow !! You cannot PUSH %d value\n",val);
	else
	{	ptr->top++;
		ptr->arr[ptr->top]=val;
		printf("\nYour value %d is succesfully Pushed in the Stack \n",val);
	}
}
int pop(struct stack *ptr)
{
	if(is_empty(ptr))
	printf("\nStack Underflow !! You cannot POP any value\n");
	else
	{
		int a=ptr->arr[ptr->top];
		ptr->top--;
		return a;
	}
}

void view_top(struct stack *ptr)
{	int y;
	if(is_empty(ptr))
	printf("\nStack Underflow !! The TOP value does not exist\n");
	else
	{
		y=ptr->arr[ptr->top];
		printf("\nTOP value of this Stack is %d\n",y);
	}
}
void view_bottom(struct stack *ptr)
{
	if(is_empty(ptr))
	printf("\nStack Underflow !! The BOTTOM value does not exist\n");
	else
	{
			int x=ptr->arr[0];
		printf("\nBOTTOM value of this Stack is %d\n",x);
	}
}
void view_peek(struct stack *ptr,int pos)
{
	if(ptr->arr[pos]==0)
	printf("\nThis position does not exist any value\n");
	else
	{
		int val=ptr->arr[pos-1];
		printf("\nThe %d position value is %d\n",pos,val);
	}
}
void view_whole_stack_value(struct stack *ptr)
{
	int index=ptr->top;
	if(is_empty(ptr))
	printf("\nStack Underflow !! The value does not exist\n");
	else
	{
		for(int i=0;i<=index;i++)
		printf("\nThe element of %d position is %d\n",i+1,ptr->arr[i]);
	}
}

int main()
{
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->size=10;
	s->top=-1;
	s->arr=(int*)malloc(s->size*sizeof(int));
	int k,l,m,n;
	do{
		printf("\n\nFor Exit Enter 0\nFor PUSH operation Enter 1\n");
		printf("For POP operation Enter 2\nFor TOP value viewing Enter 3\n");
		printf("For BOTTOM value viewing Enter 4\nFor viewing any position value in the Stack Enter 5\n");
		printf("For viewing the whole Stack value Enter 6\n");
		scanf("%d",&l);
	switch(l)
	{	case 1:
			{
				printf("\n Enter the Pushing value\n");
				scanf("%d",&m);
				push(s,m);
			}
			break;
	case 2:
		{
			n=pop(s);
			printf("\nThe value %d is Poped up from the Stack",n);
		}
		break;
	case 3 :
		{	view_top(s);
		}
		break;
	case 4 :
		{	view_bottom(s);
		}
		break;
	case 5 :
		{
			printf("\nEnter the position that You need to view the value\n");
			scanf("%d",&k);
			view_peek(s,k);
		}
		break;
	case 6 :
		{
			view_whole_stack_value(s);
		}
		break;	
	case 0 :
		{	printf("\nPROGRAM TERMINATED!!");
        }
         break;
	default :
		{
			printf("\nYour choice is Incorrect\n ");
		}
		break;
}
}while(l!=0);
printf("\nThank You for using my Stack\nCreated by saikat@2024\n");	 
return 0;
}

