#include <stdio.h>

int main(void)
{
    long long int sum = 1;
    for (long long int i = 10; i <= 15; i++)
    {
        sum *= i;
    }
    printf("%lli\n", sum);
}


