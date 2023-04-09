#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int **a=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        a[i]=(int *)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++){
        int *b=(int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
           
        }
    }
    for(int i=0;i<n;i++){
        int *b=(int *)malloc(n*sizeof(int));
        printf("%d ",i);
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                printf("%d ",j);
            }
        }
        printf("\n");
    }
}