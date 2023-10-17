//Function to compute GCD of x and y

#include <stdio.h>
#include <math.h>

int gcd(int x,int y)
{
    if (y==0) return x;
    else return gcd(y,x%y);
}

int main() 
{
    int x,y;
    scanf("%d %d",&x,&y);
    int a=gcd(x,y);
    printf("GCD of %d and %d: %d",x,y,a);
    return 0;
}