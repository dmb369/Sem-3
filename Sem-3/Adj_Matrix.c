// Adjacency Matrix Implementation

#include <stdio.h>

int main() 
{
    int m;
    printf("Enter the number of nodes:");
    scanf("%d",&m);
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
            
        int q;
        printf("Is there any more connection?");
        scanf("%d",&q);
        
        if (q!=1) k=-1;
    }
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++) printf("%d",a[i][j]);
        printf("\n");
    }
    
    return 0;
}