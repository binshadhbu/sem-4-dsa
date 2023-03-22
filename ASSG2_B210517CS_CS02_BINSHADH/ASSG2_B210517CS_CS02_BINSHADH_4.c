#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
void linear(int a[], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            c++;
    }

    int count = 0;
    int *b = (int *)malloc(n * sizeof(int));
    int index = 0;
    for (int i = 0; i < c; i++)
    {
        index = (a[i]) % n;
        int j = 1;
        while (*(b + index) != 0)
        {
            count++;
            index = (a[i] + j) % n;
            j++;
        }
        *(b + index) = a[i];
    }
    for (int i = 0; (i < c) && a[i] != 0; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == *(b + j))
            {
                printf("%d ", j);
            }
        }
    }
    printf("\n");
    printf("%d", count);
    printf("\n");
}

int prime(int n)
{
    int check = 1, j;
    if (n == 3)
        return 2;
    for (int i = n - 1; i > 1; i--)
    {
        check = 1;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                check = 0;
                break;
            }
        }
        if (check == 1)
            return i;
    }
}

void quadratic(int a[], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            c++;
    }

    int count = 0;
    int *b = (int *)malloc(n * sizeof(int));
    int index = 0;
    for (int i = 0; i < c; i++)
    {
        index = (a[i]) % n;
        int j = 1;
        while (*(b + index) != 0)
        {
            count++;
            index = (a[i] + j * j) % n;
            j++;
        }
        *(b + index) = a[i];
    }
    for (int i = 0; (i < n) && a[i] != 0; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == *(b + j))
            {
                printf("%d ", j);
            }
        }
    }
    printf("\n");
    printf("%d", count);
}
void doublehashing(int a[], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            c++;
    }

    int count = 0;
    int *b = (int *)malloc(n * sizeof(int));
    int index = 0, j = 0;
    int p = prime(n);
    for (int i = 0; i < c; i++)
    {
        j = 0;
        index = a[i] % n;
        while (*(b + index) != 0)
        {
            count++;
            index = (a[i] + j * (p - a[i] % p)) % n;
            j++;
        }
        *(b + index) = a[i];
    }
    for (int i = 0; (i < n) && a[i] != 0; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == *(b + j))
                printf("%d ", j);
        }
    }
    printf("\n");
    printf("%d", count - 2);
}
int main()
{
    int n;
    int i;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == '\0')
            break;
    }
    // printf("i is %d \n",i);
    linear(a, n);
    quadratic(a, n);
    printf("\n");
    doublehashing(a, n);
}