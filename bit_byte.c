#include <stdio.h>

void check(int i);

int main(void)
{
    for (int i = 100; i < 1000; i++)
    {
        check(i);
    }
    return 0;
}

void check(int i)
{
    int a[3];
    int tmp = i;
    for (int i = 2; i >= 0; i--)
    {
        a[i] = tmp % 10;
        tmp /= 10;
    }

    if (a[1] == a[2]) return;

    int b[4];
    int sol = i * 8;
    tmp = sol;
    for (int k = 3; k >= 0; k--)
    {
        b[k] = tmp % 10;
        tmp /= 10;
    }

    if (a[0] != b[0] || a[2] != b[2]) return;
    for (int c = 0; c < 3; c++)
    {
        for (int d = c + 1; d < 4; d++)
        {
            if (b[c] == b[d]) return;
        }
    }
    printf("%i x 8 = %i\n", i, sol);
    return;
}