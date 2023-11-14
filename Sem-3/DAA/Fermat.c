//Fermat's Primality Test

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

// Fermat's primality test function
int isPrime(unsigned long long n, int k) {

    while (k > 0) {
        
        for (int a=1; a<n; a++)
        {
            if (power(a, n - 1, n) != 1)
            return 0; // Not prime
            k--;
        }
        
    }

    return 1; // Likely prime
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
