//Depth First Search Implementation

#include <stdio.h>

int main() 
{
    int m;
    printf("Enter the number of nodes:");
    scanf("%d",&m);
    
    //Visited array counter
    int c[m];
    for (int i=0; i<m; i++) c[i]=1;
    
    //Matrix Implmentation
    int a[m][m];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++) a[i][j]=0;
    }
    
    //Making the graph
    int k=1;
    while(k==1)
    {
        printf("Enter the edges connection:");
        
        int f,s;
        scanf("%d %d",&f, &s);
    
        a[f][s]=1;
        a[s][f]=1;
            
        int q;
        printf("Is there any more connection?");
        scanf("%d",&q);
        
        if (q!=1) k=-1;
    }
    
    //Starting to Explore
    int v;
    printf("Enter the starting vertex for BFS:");
    scanf("%d",&v);
    int b[m];

    int f=0;
    b[f]=v;
    c[v]=0;
    for(int j=0; j<m; j++)
    {
        if (a[v][j]==1 && a[v][v]!=1 && c[j]==1) 
        {
            c[j]=0;
            v=j;
            b[++f]=j;
            j=0;
        }
    }
    
    int g=f;
    while(g>=0)
    {
        int v=b[g];
        for(int j=0; j<m; j++)
        {
            if (a[v][j]==1 && a[v][v]!=1 && c[j]==1) 
            {
                c[j]=0;
                v=j;
                b[++f]=j;
                j=0;
            }
        }
        --g;
    }
    
    //Print the DFS
    for(int i=0; i<m; i++) printf("%d ",b[i]);
    
    return 0;
}