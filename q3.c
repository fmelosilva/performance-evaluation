#include <stdio.h>
#include <math.h>

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

void transpose(float out[8][8], float num[8][8], float fac[8][8], float r)
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
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            out[i][j] = b[i][j] / d;
        }
    }
}

void cofactor(float out[8][8], float num[8][8], float f)
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
    transpose(out, num, fac, f);
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
    float out[8][8], in[8][8] = {{4.85, 0.85, 1.88, 4.29, 8.05, 7.46, 7.01, 3.66},
                                 {4.54, 6.55, 5.81, 7.85, 8.88, 4.91, 7.90, 1.17},
                                 {5.86, 1.53, 8.58, 3.29, 7.93, 1.15, 1.36, 0.15},
                                 {3.37, 1.26, 5.27, 8.94, 2.79, 5.58, 8.81, 6.87},
                                 {1.74, 4.90, 1.04, 7.79, 4.22, 7.00, 0.67, 0.57},
                                 {4.03, 6.62, 2.52, 0.49, 4.96, 3.78, 5.70, 7.21},
                                 {4.04, 4.25, 0.47, 5.29, 1.62, 4.27, 1.16, 4.63},
                                 {5.53, 7.21, 8.68, 3.33, 5.74, 4.09, 7.80, 0.72}};

    cofactor(out, in, n);
    print_matrix(out);

    return 0;
}
