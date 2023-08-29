// GCD of 2 Numbers

#include <stdio.h>

int main()
{
    int a, b, gcd;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    for(int i=1; i <= a && i <= b; i++) if(a%i==0 && b%i==0) gcd = i;
    
    printf("G.C.D of %d and %d is: %d", a, b, gcd);

    return 0;
}