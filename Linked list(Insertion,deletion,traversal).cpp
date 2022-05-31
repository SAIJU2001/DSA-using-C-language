#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void Traversal_Linked_List(struct node *ptr)
{
	while(ptr!=NULL)
	{	printf("element : %d\n",ptr->data);
		ptr=ptr->next;
	}
	
}
//inserting at begining

struct node *insert_at_first(struct node *head,int data)
{
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=head;
	printf("\nYour value %d is inserted in the linked list.\n",ptr->data);
	return ptr;
};
//inserting at end

struct node *insert_at_end(struct node *head,int data)
{	
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	  ptr->data = data;
    struct node *p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    printf("\nYour value %d is inserted in the linked list.\n",ptr->data);
    return head;
}

//inserting at index

struct node *insert_at_index(struct node *head,int data,int index)
{	
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	  ptr->data = data;
    struct node *p = head;
    struct node *q=head->next;
    int i=0;

    while(i!=(index-1))
	{
        p = p->next;
        q=q->next;
        i++;
    }
    p->next = ptr;
    ptr->next = q;
    printf("\nYour value %d is inserted in the linked list.\n",ptr->data);
    return head;
	
};

//deletion at begining

struct node *deletion_at_first(struct node *head)
{	struct node *p;
	int l;
	p=head;
	l=p->data;
	head=head->next;
	free(p);
	printf("\nThe value %d is deleted from thr linked list.\n",l);
	return head;
};

//deletion at end

struct node *deletion_at_end(struct node *head)
{	
	int l;
	struct node *p=head;
	struct node *q=head->next;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next;
    }
    l=q->data;
    p->next = NULL;
    free(q);
    printf("\nThe value %d is deleted from thr linked list.\n",l);
    return head;
};

//deletion at index

struct node *deletion_at_index(struct node *head,int index)
{	
    struct node *p = head;
    struct node *q=head->next;
    int i=0,l;

    while(i!=(index-1))
	{
        p = p->next;
        q=q->next;
        i++;
    }
    l=q->data;
    p->next =q->next;
    free(q);
    printf("\nThe value %d is deleted from thr linked list.\n",l);
    return head;
	
};

	 


int main()
{
	struct node* head = NULL;
    int k,val,pos;

    do
    {
    	printf("\nEnter your choice(1-9): ");
        printf("\nPress 1 to Add at the beginning of Linked List");
        printf("\nPress 2 to Add at the end of Linked List");
        printf("\nPress 3 to Add in an intermediate position of Linked List");
        printf("\nPress 4 to Display the Linked List");
        printf("\nPress 5 to Delete an element from the beginning of Linked List");
        printf("\nPress 6 to Delete an element from the end of Linked List");
        printf("\nPress 7 to Delete an element from an intermediate position of Linked List");
        printf("\nPress 9 to EXIT from the Linked List\n");
        scanf("%d",&k);

        switch(k)
        {
        case 1 :
            printf("\nEnter value: ");
            scanf("%d",&val);
            head=insert_at_first (head,val);
            break;
        case 2 :
            printf("\nEnter value: ");
            scanf("%d",&val);
            insert_at_end(head,val);
            break;
        case 3:
            printf("\nEnter position from the start: ");
            scanf("%d",&pos);
            printf("Enter value: ");
            scanf("%d",&val);
            head =insert_at_index(head,val,pos);
            break;
        case 4 :
            Traversal_Linked_List(head);
            break;
        case 5 :
        	head=deletion_at_first(head);
            break;
        case 6 :
        	head=deletion_at_end(head);
            break;
		case 7 :
            printf("\nEnter position to delete: ");
            scanf("%d",&pos);
            head =deletion_at_index(head,pos);
            break;
        case 9 :
            printf("\nPROGRAM TERMINATED!!");
            printf("\nThank You for Using my Linked List");
            printf("\nCreated and Designed by SAIKAT");
            break;
        default :
            printf("\nWrong Entry!!\n");
            break;
        }

    }while(k!=9);
     
	
return 0;
}


