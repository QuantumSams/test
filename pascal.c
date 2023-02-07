#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkInt(char * s);
int pascal(int k, int n);
void pyramid(void);

int main (void)
{
    char s1[50], s2[50];
    printf("Nhap k: "); scanf("%s", s1);
    printf("Nhap n: "); scanf("%s", s2);

    if (!checkInt(s1) || !checkInt(s2)) 
    {
        printf("k va n khong hop le\n");
        return -1;
    }
    int k = atoi(s1), n = atoi(s2);
    if (k > n) 
    {
        printf("k khong hop le (lon hon n)\n");
        return -1;
    }
    printf("%iC%i: %i\n", n, k, pascal(k, n));
    pyramid();
    return 0;
}

int checkInt(char * s)
{
    for (int i = 0; i < strlen(s); i++)
    {
       if (s[i] == '.' || s[i] == ',' || s[i] == '-') return 0;
    }
    return 1;
}

int pascal(int k, int n)
{
    if (k == 0 || k == n) return 1;
    else return pascal(k, n - 1) + pascal(k - 1, n - 1);
}

void pyramid(void)
{
    int l;
    printf("So dong: "); scanf("%i", &l);

    for (int i = 0; i < l; i++)
    {
        for (int _ = l - 1; _ >= i; _--) printf(" ");
        for (int k = 0; k <= i; k++)
        {
            printf("%i ", pascal(k, i));
        }
        printf("\n");
    }
    return;
}