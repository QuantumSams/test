#include <stdio.h>

void printMtrx(float mtx[200][200], int row, int col);
float swap(float mtx[200][200], int row, int col);

int main(void)
{
    float mtx[200][200];
    int m, n;
    printf("So hang ma tran: "); scanf("%i", &m);
    printf("So cot ma tran: "); scanf("%i", &n);

    if (m != n) 
    {
        printf("Khong phai ma tran vuong!\n");
        return -1;
    }

    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < n; k++)
        {
            printf("[%i][%i]: ", i+1, k+1);
            scanf("%f", &mtx[i][k]);
        }
        printf("\n");
    }
    printMtrx(mtx, m, n);
    printf("Tong duong cheo: %f\n", swap(mtx, m, n));
    printMtrx(mtx, m, n);
}

void printMtrx(float mtx[200][200], int row, int col)
{
    for (int a = 0; a < row; a++)
    {
        for (int b = 0; b < col; b++)
        {
            printf("%.2f ", mtx[a][b]);
        }
        printf("\n");
    }
    printf("\n");
}

float swap(float mtx[200][200], int row, int col)
{
    if (row != col)
    {
        return -1;
    }
    
    float sum = 0;
    for (int i = 0; i < row; i++)
    {
        float max = mtx[i][0];
        int pos = 0;
        for (int k = 1; k < col; k++)
        {
            if (mtx[i][k] > max)
            {
                max = mtx[i][k];
                pos = k;   
            }
        }
        mtx[i][pos] = mtx[i][i];
        mtx[i][i] = max;
        sum += max;
    }
    return sum;
}


