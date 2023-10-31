//Brute- Force algorithm for primality testing

#include <stdio.h>

int main() 
{
    printf("Enter a number:");
    int n;
    scanf("%d",&n);
    
    int flag=0;
    for (int i=2; i<=n/2; i++)
    {
        if (n%i==0)
        {
            flag=-1;
            break;
        }
    }
    
    if (flag==0) printf("%d is prime",n);
    else printf("%d is composite",n);

    return 0;
}