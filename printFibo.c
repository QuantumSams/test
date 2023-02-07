#include <stdio.h>

void fibo(int limit);
int main(void)
{
    int x; 
    printf("Limit: ");
    scanf("%i", &x);
    fibo(x);
    return 0;
}
void fibo(int limit)
{
    int a = 0, b = 1, c = 1;

    while (c < limit)
    {
        printf("%i ", c);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}