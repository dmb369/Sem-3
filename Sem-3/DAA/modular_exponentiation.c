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
    int k=bin_exp(x,y);
    printf("%d",k%n);
    return 0;
}