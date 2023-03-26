#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int a[],int n,int i){
    int roi=i,li=2*i+1,ri=2*i+2;
    if(li<n&&a[li]>a[i]){
        swap(&a[li],&a[i]);
        heapify(a,n,li);
    }
    if(ri<n&&a[ri]>a[i]){
        swap(&a[ri],&a[i]);
        heapify(a,n,ri);
    }

}

void sort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>-1;i--){
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
    
}
void extract(int a[], int n)
{
    swap(&a[0], &a[n +1]);
    n--;
    heapify(a, n, 0);
    
}
void solve(int a[],int n){
    int cost=0;
    int total=0;
    sort(a,n);
    while(n>1){
        cost =a[0]+a[1];
        total+=cost;
        extract(a,a[0]);
        a[0]=cost;
        n=n-1;
        sort(a,n);
    }
    printf("%d ",total);
}


int main(){

        int n;
        scanf("%d",&n);
        int a[n];
      //int *a=(int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        solve(a,n);
        
    
}