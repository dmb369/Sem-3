//Division

#include <stdio.h>

int divi(int x, int y)
{
    if (x<y) return 0;
    return (1+divi(x-y,y));
}

int main() 
{
    int x,y;
    scanf("%d %d",&x,&y);
    int c=divi(x,y);
    printf("%d",c);
    return 0;
}