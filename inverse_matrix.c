#include <stdio.h>
#include <math.h>
#define MAX 50

void copy(float dest[MAX][MAX], float src[MAX][MAX], int l);
int getMatrix(float m[MAX][MAX]);
void printMatrix(float m[MAX][MAX], int l);
int delete(float m[MAX][MAX], int l, int row, int col, float m2[MAX][MAX], float mold[MAX][MAX]);
float coFactor(float m[MAX][MAX], int l, int row, int col, float res, float mold[MAX][MAX]);
float det(float m[MAX][MAX], float co[MAX][MAX], int l, float mold[MAX][MAX]);
void inverse(float co[MAX][MAX], float result[MAX][MAX], int l, float det);

int main(void)
{
    float m[MAX][MAX], co[MAX][MAX], mold[MAX][MAX], result[MAX][MAX];

    int l = getMatrix(m);
    if (l == 1 || l == 2)
    {
        printMatrix(m, l);
        return 0;
    }
    else if (l == -1) return -1;

    copy(mold, m, l);
    float d = det(m, co, l, mold);
    if (d == 0)
    {
        printf("Det = 0\n");
        return 0;
    } 
    printf("%f\n", d);

    inverse(co, result, l, d);
    printMatrix(result, l);

    return 0;
}

void copy(float dest[MAX][MAX], float src[MAX][MAX], int l)
{
     for (int i = 0; i < l; i++)
    {
        for (int k = 0 ; k < l; k++)
        {
            dest[i][k] = src[i][k];
        }
    }
    return;
}

int getMatrix(float m[MAX][MAX])
{   
    int l;
    printf("Size of square matrix: "); scanf("%i", &l);
    for (int i = 0 ; i < l; i++)
    {
        for (int k = 0 ; k < l; k++)
        {
            printf("#[%i][%i]: ", i + 1, k + 1); scanf("%f", &m[i][k]);
        }
        printf("\n");
    }

    if (l == 2)
    {
        float det = (m[0][0] * m[1][1]) - (m[1][0] * m[0][1]);
        if (det == 0)
        {
            printf("No inverse matrix is applicable for this matrix - det = 0\n");
            return -1;
        }
        float tmp = m[0][0];
        m[0][0] = m[1][1];
        m[1][1] = tmp;


        for (int i = 0; i < l; i++)
        {
            for (int k = 0 ; k < l; k++)
            {
                m[i][k] *= pow(-1, i + k + 2) * (1 / det);
            }
        }
    }
    else if (l == 1)
    {
        if (m[0][0] == 0) 
        {
            printf("No inverse matrix is applicable for this matrix - det = 0\n");
            return -1;
        }
        m[0][0] = 1/m[0][0];
    }
    return l;
}

void printMatrix(float m[MAX][MAX], int l)
{
    
    for (int i = 0 ; i < l; i++)
    {
        for (int k = 0 ; k < l; k++)
        {
            printf("%f ", m[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

int delete(float m[MAX][MAX], int l, int row, int col, float m2[MAX][MAX], float mold[MAX][MAX])
{
    copy(m2, m, l);
    for(int i = row; i < l; i++)
    {
        for (int k = 0; k < l; k++)
        {
            m2[i][k] = m[i + 1][k];
        }
    }
    copy(m, m2, l);

    for (int b = col; b < l; b++)
    {
        for (int a = 0; a < l; a++)
        {
            m2[a][b] = m[a][b + 1];
        }
    }
    copy(m, mold, l);
    l--;
    return l;
}
float coFactor(float m[MAX][MAX], int l, int row, int col, float res, float mold[MAX][MAX])
{
    float _[MAX][MAX];
    int _l = delete(m, l, row, col, _, mold);

    if(_l == 2)
    {
        res = ((_[0][0] * _[1][1]) - (_[0][1] * _[1][0]));
        return res;
    }

    float __[MAX][MAX];
    int __l = delete(m, l, row, col, __, mold);

    for (int i = 0; i < l; i++)
    {
        float pos = __[0][i] * pow(-1, i + 2);
        res += pos * coFactor(__, __l, 0, i, res, mold);
        __l = delete(m, l, row, col, __, mold);
    }
    return res;
}

float det(float m[MAX][MAX], float co[MAX][MAX], int l, float mold[MAX][MAX])
{
    float det = 0;
    for (int i = 0; i < l; i++)
    {
        for (int k = 0; k < l; k++)
        {
            co[i][k] = coFactor(m, l, i, k, 0, mold) * pow(-1, i + k + 2);
            if (i == 0)
            {
                det += m[i][k] * co[i][k];
            }
        }
    }
    return det;
}

void inverse(float co[MAX][MAX], float result[MAX][MAX], int l, float det)
{
    for (int i = 0 ; i < l; i++)
    {
        for (int k = 0; k < l; k++)
        {
            result[k][i] = co[i][k] / det;
        }
    }
}