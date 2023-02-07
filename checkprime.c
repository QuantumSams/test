#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int getInt(char * s);
int checkPrime(int x);
int checkInt(char * s);

int main(void)
{
    int x = getInt("Nhap so: ");
    if (x == -7) 
    {
        printf ("Khong phai so nguyen to\n");
        return 0;
    }
    printf(checkPrime(x) ? "%i la so nguyen to\n" : "%i KHONG PHAI so nguyen to\n", x);

    for (int i = 2; i <= x; i++)
    {
        if (checkPrime(i)) printf("%i ", i);
    }
    printf("\n");
    return 0;
}

int getInt(char * s)
{
    char tmp[1000]; int i;
    printf("%s", s); 
    scanf("%s", tmp);
    if (checkInt(tmp))
    {
        i = atoi(tmp);
        return i;
    } 
    return -7;
}

int checkPrime(int x)
{
    if (x == 2 || x == 3) return 1;
    if (x <= 1 || x % 2 == 0 || x % 3 == 0) return 0;

    for (int i = 5; i <= sqrt(x); i+= 6)
    {
        if (x % i == 0 || x % (i + 2) == 0) return 0;
    }
    return 1;
}

int checkInt(char * s)
{
    for (int i = 0; i < strlen(s); i++)
    {
       if (s[i] == '.' || s[i] == ',') return 0;
    }
    return 1;
}