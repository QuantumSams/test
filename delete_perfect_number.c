#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define M 1000

int checkInt(char * s);
int getArr(float arr[M], int status[M]);
void perfect(int i);
int deleteP(float arr[M], int status[M], int intel[M], int l);
int main(void)
{
    float arr[M];
    int status[M], intel[M], count = 0;
    int l = getArr(arr, status);

    for (int a = 0; a < l; a++)
    {
        if (status[a] == 1 && arr[a] > 0)
        {
            intel[count] = arr[a];
            count++;
        }
    }
    l = deleteP(arr, status, intel, l);
     for (int k = 0; k < l; k++)
    {
        printf(status[k]? "%g ": "%.2f ", arr[k]);
    }
    printf("\n");
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
int getArr(float arr[M], int status[M])
{
    int l; printf("So phan tu cua mang: "); scanf("%i", &l);
    
    for (int i = 0; i < l; i++)
    {
        printf("#%i: ", i); 
        char tmp[M];
        scanf("%s", tmp);
        status[i] = checkInt(tmp);
        arr[i] = atof(tmp);
    }

    for (int k = 0; k < l; k++)
    {
        printf(status[k]? "%g ": "%.2f ", arr[k]);
    }
    printf("\n");
    return l;
}

void perfect(int i)
{
    int sum = 1, k = 2;
    while (k < sqrt(i))
    {
        if (i % k == 0) sum += k + i / k;
        k++;
    }
    if (sum == i) printf("%i ", i);
    return;
}

int deleteP(float arr[M], int status[M], int intel[M], int l)
{
    int i_count = 0, arr_count = l;
    for (int i = 0; i < l; i++)
    {
        if(arr[i] == intel[i_count] && status[i] == 1)
        {
            for (int j = i; j < arr_count - 1; j++)
            {
                arr[j] = arr[j + 1];
                status[j] = status[j + 1];
            }
            arr_count--;
            i_count++;
        }
    }
    return arr_count;
}


