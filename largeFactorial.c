#include <stdio.h>

int fractal(int x, int size, int arr[]);

int main(void)
{
    int arr[200] = {0};
    arr[0] = 1;
    int x;
    scanf("%i", &x);

    int size = 1;

    for (int i = 2; i <= x; i++)
    {
        size = fractal(i, size, arr);
    }

    for (int k = size - 1; k >= 0; k--)
    {
        printf("%i", arr[k]);
    }
    printf("\n");
}

int fractal(int x, int size, int arr[])
{
    int tmp = 0;
    for (int i = 0; i < size; i++)
    {
        int middle_man = (arr[i] * x) + tmp;
        arr[i] = middle_man % 10;
        tmp = middle_man / 10;
    }

    while (tmp != 0)
    {
        arr[size] = tmp % 10;
        tmp = tmp / 10;
        size++;
    }
    return size;
}