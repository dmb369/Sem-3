//Miller Rabin Primality Test

#include <stdio.h>
#include <stdlib.h>

// Function to calculate (a^b) % m
unsigned long long power(unsigned long long a, unsigned long long b, unsigned long long m) 
{
    unsigned long long result = 1;

    while (b > 0) 
    {
        result = (result * a) % m;
        b--;
        a = (a * a) % m;
    }

    return result;
}

//Miller-Rabin primality test function
int isPrime(unsigned long long n, int k) 
{
    if (n%2==0 && n!=2) return 0;
    
    unsigned long long m=n-1;
    while (m%2!=0) m/=2;

    while (k > 0)
    {
        int a=2;
        int res=power(a,m,n);
        while (res==1 || res==-1)
        {
            res=power(res,2,n);
        }
        if (res==-1) return 0;
        if (res==1) return 1;
    }
}

int main() {

    // Number to be tested for primality
    unsigned long long num;
    printf("Enter a number to test for primality: ");
    scanf("%llu", &num);

    // Number of iterations for the test (higher is more accurate)
    int k;
    printf("Enter the number of iterations (k): ");
    scanf("%d", &k);

    // Perform Fermat's primality test
    if (isPrime(num, k))
        printf("%llu is likely to be prime.\n", num);
    else
        printf("%llu is composite.\n", num);

    return 0;
}
