#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

int *mra(int al2, int mn)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int *as = 0;
    int i;
    as = (int *)malloc(al2 * sizeof(int));
    srand(tv.tv_usec);
    for (i = 0; i < al2; ++i)
    {
        as[i] = (rand() % (mn - 2)) + 2;
    }
    return as;
}

int ip(int x)
{
    int y;
    for (y = 2; y < x; ++y)
    {
        if ((x % y) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int *fp(int al3, int *arr)
{
    int *as = 0;
    int i;
    as = (int *)malloc(al3 * sizeof(int));
    for (i = 0; i < al3; ++i)
    {
        if (ip(arr[i]))
        {
            as[i] = 1;
        }
    }
    return as;
}

int fl(int al4, int *nums, int *ips)
{
    if (al4 == 0)
    {
        return -1;
    }
    if (!ips[al4 - 1])
    {
        return fl(al4 - 1, nums, ips);
    }
    if (fl(al4 - 1, nums, ips) > nums[al4 - 1])
    {
        return fl(al4 - 1, nums, ips);
    }

    return nums[al4-1];
}

void po(int al5, int *nums, int *ips, int l)
{
    int i;
    for (i = 0; i < al5; ++i)
    {
        if (ips[i])
        {
            printf("% d ", nums[i]);
        }
    }
    printf("\n The largest prime is %d \n", l);
}

int main(void)
{
    int i, l, al, al1, mn, mn1;
    int *ra = 0;
    int *pr = 0;
    int k = 1000;
    al1 = 25;
    al = al1;
    mn1 = 10000;
    mn = mn1;
    printf("Generate %d list(s) of size %d of prime numbers - Each prime is within(0, %d) \n", k, al, mn);
    for (i = 0; i < k; i++)
    {
        al = al1;
        mn = mn1;
        ra = mra(al, mn);
        pr = fp(al, ra);
        l = fl(al, ra, pr);
        printf("\n List number %d \n", i + 1);
        po(al, ra, pr, l);
        free(ra);
        free(pr);
    }
    return 0;
}