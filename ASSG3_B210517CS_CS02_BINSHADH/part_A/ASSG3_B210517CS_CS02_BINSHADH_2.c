#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int a[], int n, int i)
{
    int roi = i, le = 2 * i + 1, re = 2 * i + 2;
    if (le < n && a[le] < a[i])
    {
        swap(&a[le], &a[i]);
        heapify(a, n, le);
    }
    if (re < n && a[re] < a[i])
    {
        swap(&a[re], &a[i]);
        heapify(a, n, re);
    }
}
void min_heap(int a[], int n)
{
    for (int i = n / 2 - 1; i > -1; i--)
    {
        heapify(a, n, i);
    }
}
void insert(int a[], int n, int x)
{
    a[n - 1] = x;
    min_heap(a, n);
}
void print(int a[], int n)
{
    // g
    // printf("%s", "array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void delete(int a[], int n, int num)
{
    // n--;
    int check = 1;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
        {
            printf("%d ", num);
            check = 0;
            index = i;
            break;
        }
    }
    if (check)
    {
        printf("%d ", -1);
        return;
    }
    if (!check)
    {
        swap(&a[index], &a[n - 1]);
        heapify(a, n - 1, 0);
    }
}
void extract(int a[], int n)
{
    swap(&a[0], &a[n - 1]);
    n--;
    heapify(a, n, 0);
    print(a, n);
}
void minimum(int a[])
{
    printf("%d", a[0]);
    printf("\n");
}
void decrease(int a[], int x, int y, int n)
{
    int check = 0, index = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            check = 1;
            index = i;
            printf("%d ", y);
            break;
        }
    }
    if (!check)
    {
        printf("%d", -1);
        return;
    }
    a[index] = y;
    min_heap(a, n);
}
int main()
{
    int *a = (int *)malloc(100 * sizeof(int));
    int size = 0;
    int num, n = 0;
    char c;
    int x, y;
    while (1)
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
            scanf("%d", &num);
            size++;
            insert(a, size, num);
            break;
        case 'd':
            scanf("%d", &num);
            delete (a, size, num);
            size--;

            printf("\n");
            break;
        // case
        case 'p':
            print(a, size);
            break;
        case 'x':
            extract(a, size--);
            break;
        case 'g':
            minimum(a);
            break;
        case 'e':
            return 0;
        case 'r':
            scanf("%d %d", &x, &y);
            decrease(a, x, y, size);
            printf("\n");
            break;
        }
    }
}