#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int checkInt(char * s);
int checkFibo(long long int x);


int main(void)
{
    char tmp[50000];
    printf("Nhap so: "); scanf("%s", tmp);
    if (!checkInt(tmp))
    {
        printf("Khong phai so Fibo\n");
        return -1;
    }
    long long int i = atoi(tmp);
    printf(checkFibo(i) ?"La so fibo\n": "KHONG PHAI Fibo\n");
    return 0;
}

int checkInt(char * s)
{
    for (int i = 0; i < strlen(s); i++)
    {
       if (s[i] == '.' || s[i] == ',') return 0;
    }
    return 1;
}

int checkFibo(long long int x)
{
    if (fmod(sqrt((5 * pow(x, 2)) + 4), 1) == 0 || fmod(sqrt((5 * pow(x, 2)) - 4), 1) == 0) return 1;
    else return 0;
}