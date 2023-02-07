#include <stdio.h>

int isTri(int a, int b, int c);
int isSqr(int a, int b, int c);
int isEven(int a, int b, int c);
int isObt(int a, int b, int c);
int main(void)
{
    int a, b, c;
    printf("Cac canh: ");
    scanf("%i %i %i", &a, &b, &c);
   
    if (isTri(a, b, c) == 0)
    {
        printf("Khong phai tam giac");
        return 0;
    }

    else if (isEven(a, b, c) == -1)
    {
        printf(isSqr(a, b, c) ? "Tam giac vuong can\n":"Tam giac can\n");
    }
    else if (isSqr(a, b, c))
    {
        printf("Tam giac vuong\n");
    }
    else if (isEven(a, b, c) == 1)
    {
        printf("Tam giac deu");
    }
    else if(isObt(a, b, c))
    {
        printf("Tam giac tu\n");
    }
    else
    {
        printf("Tam giac nhon\n");
    }
    return 0;
    
}

int isTri(int a, int b, int c)
{
    return ((a + b > c && b + c > a && a + c > b)? 1:0);
}

int isSqr(int a, int b, int c)
{
    return ((a * a == b * b + c * c || b * b == a * a + c * c ||c * c == b * b + a * a)? 1:0);
}

int isEven(int a, int b, int c)
{
    if (a == b && b == c) return 1;
    else if (a != b && b != c) return 0;
    else return -1;
}

int isObt(int a, int b, int c)
{
    return ((a * a > b * b + c * c || b * b > a * a + c * c ||c * c > b * b + a * a)? 1:0);
}
