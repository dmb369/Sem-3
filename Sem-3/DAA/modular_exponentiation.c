//Function to implement Modular Exponentiation

#include <stdio.h>
#include <math.h>

int bin_exp(int x,int y)
{
    if (y==0) return 1;
    
    int res=bin_exp(x,y/2);
    
    if (y%2==0) return res*res;
    else return res*res*x;
}

int main() 
{
    int x,y;
    scanf("%d %d",&x,&y);
    int n;
    scanf("%d",&n);
    int z=bin_exp(x,y);
    
    int r;
        
    if (z==0)
    {
        r=0;
    }
    
    int l=z/2;
    r=l%n;
    
    r*=2;
    
    if (z%2!=0)
    {
        r=r+1;
        if (r>=n)
        {
            r-=n;
        }
    }
    
    if (r==n) r=0;
    
    printf("modN value is %d",r);
    return 0;
}
