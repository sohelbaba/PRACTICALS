#include<stdio.h>
#include<stdlib.h>

#define initial 1
#define waiting 2
#define visited 3
int state[max];
int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();


void BFS(int v)
{
	int i;

	insert_queue(v);
	state[v] = waiting;

	while(!isEmpty_queue())
	{
		v = delete_queue( );
		printf("%d ",v);
		state[v] = visited;

		for(i=0; i<n; i++)
		{
			if(adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}

void insert_queue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}

int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}

int delete_queue()
{
	int delete_item;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}

	delete_item = queue[front];
	front = front+1;
	return delete_item;
}
