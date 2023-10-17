//Function to multiply x and y and return the result modN

#include <stdio.h>

void mult(int x,int y, int n)
{
    int z=x*y;
    int a=z%n;
    printf("modN value is %d",a);
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