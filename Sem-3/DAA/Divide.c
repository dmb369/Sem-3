// Function to divide x and y and return the quotient and remainder.

#include <stdio.h>

void divide(int x, int y)
{
    int q,r;
    
    if (x==0) 
    {
        q=0;
        r=0;
    }
    
    int z=x/2;
    
    int b=z/y;
    q=b;
    r=z%y;
    
    q=2*q;
    r=2*r;
    
    if (x%2!=0) 
    {
        r=r+1;
        if (r>=y) 
        {
            r-=y;
            q+=1;
        }
    }
    
    printf("Quotient: %d; Remainder: %d", q,r);
}


int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    divide(x,y);
}