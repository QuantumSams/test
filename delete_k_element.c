#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int checkInt(char * s);
int add_array(int arr[], int * l);
void removeArr(int arr[], int *l, int remove);

int main(void)
{
    int arr[200];
    int l = 0;
    int remove = add_array(arr, &l);
    
    removeArr(arr, &l, remove);
    
    for (int i = 0; i < l; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}
int checkInt(char * s)
{
    for (int i = 0; i < strlen(s); i++)
    {
       if (s[i] == '.' || s[i] == ',') return 0;
    }
    return 1;
}

int add_array(int arr[], int * l)
{
    while (true)
    {
        printf("So phan tu: "); scanf("%i", l);
        if (*l >= 0) break;
    }

    for (int i = 0; i < *l; i++)
    {
        while (true)
        {
            char tmp[50];
            printf("[%i]: ", i);
            scanf("%s", tmp);
            if (checkInt(tmp))
            {
                arr[i] = atoi(tmp);
                break;
            } 
            printf("Khong phai so nguyen, nhap lai\n");
        }
    }
    int k;
    while (true)
    {
        printf("Vi tri phan tu xoa: "); scanf("%i", &k);
        if (k < *l && k > -1) break;
        printf("Vi tri khong hop le, nhap lai\n");
    }
    return k;
}

void removeArr(int arr[], int *l, int remove)
{
    if (*l - 1 == remove)
    {
        *l -= 1;
        return;
    }

    for (int i = remove; i < *l - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    *l -= 1;
    return;
}


