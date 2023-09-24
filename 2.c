#include <stdio.h>

//a sample comment

void color(int i);
void space(int a, int b, int c);
void grid();

int main(void)
{
    for(int i = 1; i <= 10; i++)
    {
        grid();
        printf("\n");
        for (int k = 2; k <= 10; k++)
        {
            color(k - 2);
            printf("%ix%i=%i", k, i, i * k);
            space(i, k, i * k);
            printf("\033[0m");
            printf("|");
        }
        printf("\n");
    }
    grid();
    
}

void color(int i)
{
    if (i > 7) i -= 7;
    printf("\033[1;3%im", i);
    return;
}

void space(int a, int b, int c)
{
    int space = 8;
    if((a > 9 || b > 9) && c >= 10) space -= 6;
    else if (a <=9 && b <= 9 && c > 9) space -= 5;
    else if (c == 100) return;
    else space -=4;

    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }
    return;
}

void grid()
{
    for (int _ = 0; _ < 90; _++)
    {
        printf("-");
    }
}