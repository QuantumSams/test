#include <stdio.h>

int mul1(long long int start, long long int end);
int zero(long long int x);
int mul2(long long int arr[1000], int l);

int main(void)
{
    int option;
    printf("Nhap so de chon mode: \n1. Tinh so 0 lien tuc\n2. Tinh so 0 ngat quang\n");
    scanf("%i", &option);

    if(option == 1)
    {
        long long int start; printf("So bat dau: "); scanf("%lli", &start);
        long long int end; printf("So ket thuc: "); scanf("%lli", &end);
        printf("%i\n", mul1(start, end));
    }
    else
    {
        long long int arr[1000]; int l;
        printf("So luong phan tu: "); scanf("%i", &l);
        for (int i = 0; i < l; i++)
        {
            printf("#%i: ", i); scanf("%lli", arr+i);
        }
        printf("%i\n", mul2(arr, l));
    }
}
    

int zero(long long int x)
{
    int sum = 0;
    while (x >= 5)
    {
        sum += x / 5;
        x /= 5;
    }
    return sum;
}

int mul1(long long int start, long long int end)
{
    int z = zero(end) - zero(start - 1);
    return z;
}

int mul2(long long int arr[1000], int l)
{
    int two = 0, five = 0;
    for (int i = 0; i < l; i++)
    {
        long long tmp = arr[i];
        while (tmp % 2 == 0)
        {
            two++;
            tmp /= 2;
        }
        tmp = arr[i];
        while (tmp % 5 == 0)
        {
            five++;
            tmp /= 5;
        }
    }
    return five >= two ? two : five;
}
