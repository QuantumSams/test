#include <stdio.h>
void p(int mid, int step);

int main(void)
{
    int count = 0;
    for (int i = 1; i <= 19; i+=2)
    {
        for (int k = 10; k >= count; k--) printf(" ");
        (i > 10)? p(i - 10, count) : p(i, count);
        count++;
    }
    return 0;
}

void p(int mid, int step)
{
    for (int i = mid - step; i <= mid + step; i++)
    {
        int tmp = i;
        if (i > mid) tmp = mid * 2 - i;
        if (tmp < 0) tmp += 10;
        printf("%i", tmp);
    }
    printf("\n");
    return;
}