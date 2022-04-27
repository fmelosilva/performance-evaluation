#include <stdio.h>
#include <math.h>
#include <time.h>

float determinant(float a[8][8], float k)
{
    float s = 1, det = 0, b[8][8];
    if (k == 1)
    {
        return a[0][0];
    }

    det = 0;
    for (int c = 0; c < k; c++)
    {
        int m = 0, n = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                b[i][j] = 0;
                if (i != 0 && j != c)
                {
                    b[m][n] = a[i][j];
                    if (n < (k - 2))
                        n++;
                    else
                    {
                        n = 0;
                        m++;
                    }
                }
            }
        }
        det = det + s * (a[0][c] * determinant(b, k - 1));
        s = -1 * s;
    }

    return det;
}

int transpose(float out[8][8], float num[8][8], float fac[8][8], float r)
{
    float b[8][8], d;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            b[i][j] = fac[j][i];
        }
    }

    d = determinant(num, r);
    if (d <= 0)
    {
        return -1;
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            out[i][j] = b[i][j] / d;
        }
    }

    return 0;
}

int cofactor(float out[8][8], float num[8][8], float f)
{
    float b[8][8], fac[8][8];
    for (int q = 0; q < f; q++)
    {
        for (int p = 0; p < f; p++)
        {
            int m = 0, n = 0;
            for (int i = 0; i < f; i++)
            {
                for (int j = 0; j < f; j++)
                {
                    if (i != q && j != p)
                    {
                        b[m][n] = num[i][j];
                        if (n < (f - 2))
                            n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
        }
    }

    return transpose(out, num, fac, f);
}

void print_matrix(float matrix[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j != 0)
            {
                printf("\t");
            }
            printf("%f", matrix[i][j]);
        }

        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int n = 8;
    float out[8][8], in[8][8];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &in[i][j]);
        }
    }

    if (determinant(in, n) == 0)
    {
        printf("\nInverse of Entered Matrix is not possible\n");
        return 0;
    }

    clock_t start = clock();
    cofactor(out, in, n);
    double cpu_time_used = ((double)(clock() - start)) / CLOCKS_PER_SEC;

    printf("inverse matrix:\n");
    print_matrix(out);
    printf("-------------\n");
    printf("time elapsed: %lf\n", cpu_time_used);

    return 0;
}
