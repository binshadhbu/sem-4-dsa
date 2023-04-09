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
    if (le < n && a[le] > a[i])
    {
        swap(&a[le], &a[i]);
        heapify(a, n, le);
    }
    if (re < n && a[re] > a[i])
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
    for(int i=n-1;i>-1;i--){
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}
void insert(int a[], int n, int x)
{
    a[n - 1] = x;
    min_heap(a, n);
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void delete(int a[], int n, int num)
{
   //  printf("%d n delete",n);//
    // n--;
    int check = 1;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
        {
            //printf("%d ", num);
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

void solve(int a[],int n){
    int cost=0,total=0;
    while(n>1){
       // printf("a[0] is:%d a[1]=%d\n",a[0],a[1]);
        cost=a[0]+a[1];
        total+=cost;
        print(a,n);
        
        delete(a,n--,a[0]);

        //printf("n: %d\n",n);
        delete(a,n--,a[0]);
        print(a,n);
        insert(a,n++,cost);
    }
    printf("%d\n",total);
}
int main()
{
    int n,size;
    scanf("%d", &n);

    int *a = (int *)malloc(n* sizeof(int));
    //int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    min_heap(a,n);
    solve(a,n);
    
}