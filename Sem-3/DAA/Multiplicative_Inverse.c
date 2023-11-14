// Inverse of x in modular arithmatic

#include <stdio.h>
 
int gcdExtended(int a, int b, int* x, int* y)
{
    if (a == 0) {
        *y = 0;
        *x = 1;
        return b;
    }
 
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    *y = x1 - (b / a) * y1;
    *x = y1;
 
    return x1;
}

int modInverse(int a, int b)
{
    int x,y;
    int g = gcdExtended(a, b, &x, &y);
     
    if (g!=1) return -1;
     
    return (y%b+b)%b;
     
}
 
// Driver Program
int main()
{
    int x, y;
    int a, b;
    scanf("%d %d",&a, &b);
    int c=modInverse(a,b);
    printf("%d",c);
    return 0;
}