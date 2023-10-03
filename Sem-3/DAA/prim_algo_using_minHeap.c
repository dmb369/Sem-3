//Implementing Prim's Algorithm
//Using Min-Heap Data Structure

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

int min_dist(int dist[], bool set[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (set[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void print_prim(int cost[V][V],int dist[])
{
    printf("Edge \t\t  Weight\n");
    for (int i=1; i<V; i++)
    {
        printf("%d - %d \t\t %d\n",dist[i],i,cost[i][dist[i]]);
    }
}

void prim(int cost[V][V])
{
    bool set[V];
    int dist[V];
    int key[V];
    
    for(int i=0; i<V; i++) 
    {
        set[i]=false;
        key[i]=INT_MAX;
    }
    
    dist[0]=-1;
    key[0]=0;
    
    for (int count=0; count<V-1; count++)
    {
        int u=min_dist(key,set);
        set[u]=true;
        
        for (int v=0; v<V; v++)
        {
            if (!set[v] && cost[u][v] && key[v]>cost[u][v])
            {
                key[v]=cost[u][v];
                dist[v]=u;
            }
        }
    }
    
    print_prim(cost,dist);
}

int main() 
{
    int n;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    
    int cost[n][n];
    printf("Enter the cost adjacency matrix:\n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    
    prim(cost);
    
    return 0;
}