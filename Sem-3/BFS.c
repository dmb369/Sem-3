// Breadth First Search Implementation

#include <stdio.h>

int main() 
{
    int m;
    printf("Enter the number of nodes:");
    scanf("%d",&m);
    
    int c[m];
    for (int i=0; i<m; i++) c[i]=1;
    
    int a[m][m];
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++) a[i][j]=0;
    }
    
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
    
    int v;
    printf("Enter the starting vertex for BFS:");
    scanf("%d",&v);
    
    int b[m];
    int f=0,d=0;
    b[d]=v;
    c[v]=0;
    
    while(d<m-1)
    {
        for (int j=0; j<m; j++)
        {
            int e=b[d];
            if (a[e][j]==1 && c[j]==1) 
            {
                b[++f]=j;
                c[j]=0;
            }
        }
        ++d;
    }
    
    //Print BFS 
    for(int i=0; i<m; i++) printf("%d ",b[i]);
    
    return 0;
}