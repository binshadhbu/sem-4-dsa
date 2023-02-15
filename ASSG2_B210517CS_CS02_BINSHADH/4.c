#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
void linear(int a[],int n){
    int count=0;
    int *b=(int *)malloc(n*sizeof(int ));
    int index=0;
    for(int i=0;i<n;i++){
        index=(a[i])%n;
        int j=1;
        while(*(b+index)!=0){
            count++;
            index=(a[i]+j)%n;
            j++;
        }
        *(b+index)=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==*(b+j)){
                printf("%d ",j);
            }
        }
    }
    printf("\n%d\n",count);
}

void quadratic(int a[],int n){
     int count=0;
    int *b=(int *)malloc(n*sizeof(int ));
    int index=0;
    for(int i=0;i<n;i++){
        index=(a[i])%n;
        int j=1;
        while(*(b+index)!=0){
            count++;
            index=(a[i]+j*j)%n;
            j++;
        }
        *(b+index)=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==*(b+j)){
                printf("%d ",j);
            }
        }
    }
    printf("\n%d\n",count);
}
int prime(int n){
    int i=0;
    for(int i=n;i>0;i--){
        for(int j=i-1;j>0;j--){
            if(i%j==0){
                i=1;
                break;
            }
        }
        if(i==0)return i;
    }
}
int doublehashing(int a[],int n){
    int count=0;
    int *b=(int *)malloc(n*sizeof(int));
    int index=0,j=0;
    int p=prime(n);
    for(int i=0;i<n;i++){
        j=0;
        index=a[i]%n;
        while(*(b+index)!=0){
            count++;
            index=(a[i]+j*(p-p%n));
        }

    }
}
int main(){
    int n;
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int b[n];

}