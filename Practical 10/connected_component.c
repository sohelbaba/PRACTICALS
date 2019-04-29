#include<stdio.h>
int Graph[10][10];
int v;
void read_graph(int n)
{
    int i,j;
    printf("Enter Edges : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("vertex [%d] to [%d] : ",i,j);
            scanf("%d",&Graph[i][j]);
        }
    }

}
void main()
{
    printf("Enter Total Number of Vertex : ");
    scanf("%d",&v);
    read_graph(v);

    printf("DFS OF GRAPH :\n");
    DFS();
}

void DFS()
{
    int visited[10];
    int k;
    //inii all vertex
    for(k=1;k<=v;k++)
        visited[k]=0;

    int j;

    for(j=1;j<=v;j++)
    {
        if(visited[j] == 0)
        {
           DFSutill(j,visited);
           printf("\n");
        }
    }
}

void DFSutill(int x,int visited[])
{
    visited[x]=1;
    printf("Node Visited : %d -> ",x);

    int i;
    for(i=1;i<=v;i++)
    {
        if(!visited[i] && Graph[x][i] == 1)
        {
            DFSutill(i,visited);
        }
    }
}

