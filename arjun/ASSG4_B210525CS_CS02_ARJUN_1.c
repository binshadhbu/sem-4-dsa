#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);

    int i,j;
    int x;
    for(i=0;i<n;++i){
        printf("%d ",i);
        for(j=0;j<n;++j){
           scanf("%d",&x);
           if(x!=0)
           printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}