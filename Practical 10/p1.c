#include<stdio.h>
int Graph[10][10];
int visited[10];
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
    DFS(1);
}
void DFS(int i)
{
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(j=1;j<=v;j++)
    {
        if(!visited[j] && Graph[i][j] == 1)
        {
           DFS(j);
        }
    }
}

