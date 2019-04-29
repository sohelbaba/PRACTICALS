#include <stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* link;
};

struct Queue
{
	struct Node *front, *rear;
};


void enQueue(struct Queue *q, int value)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = value;
	if (q->front == NULL)
		q->front = temp;
	else
		q->rear->link = temp;

	q->rear = temp;
	q->rear->link = q->front;
}

int deQueue(struct Queue *q)
{
	if (q->front == NULL)
	{
		printf ("Queue is empty");
		return INT_MIN;
	}


	int value;	if (q->front == q->rear)
	{
		value = q->front->data;
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		struct Node *temp = q->front;
		value = temp->data;
		q->front = q->front->link;
		q->rear->link= q->front;
		free(temp);
	}

	return value ;
}

void displayQueue(struct Queue *q)
{
	struct Node *temp = q->front;
	printf("\nElements in Circular Queue are: ");
	while (temp->link != q->front)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("%d", temp->data);
}

int main()
{
	struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue) );
	q->front = q->rear = NULL;

	int ch,x;
    printf("\tQUEUE OPERATION USING LINKED LIST \n");
    printf("\t 1. INSERT\n");
    printf("\t 2. DELETE\n");
    printf("\t 3. DISPLAY\n");
    printf("\t 4. EXIT\n");
    do{
        printf("\tEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            	printf("\nEnter data : ");
            	scanf("%d",&x);
            	enQueue(q,x);
                break;
            case 2:
                deQueue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                return;
            default:
                printf("\tEnter Proper Choice \n");
                break;
        }
    }while(ch !=4);

	return 0;
}
