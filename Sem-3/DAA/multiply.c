//Function to multiply x and y and return the result modN

#include <stdio.h>

void mult(int x,int y, int n)
{
    int z=x*y;
    
    int r;
        
    if (z==0)
    {
        r=0;
    }
        
    int l=z/2;
    r=l%n;

    r=2*r;
        
    if (z%2!=0)
    {
        r=r+1;
        if (r>=n)
        {
            r-=n;
        }
    }
    
    if (r==n)
    {
        r=0;
    }
        
    printf("modN value is %d",r);
}

int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    int n;
    scanf("%d",&n);
    mult(x,y,n);
    return 0;
}
