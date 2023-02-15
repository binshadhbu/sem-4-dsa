#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>


int main(){
    int n;
    scanf("%d",&n);
    int a[n],b[n];
    int c[100]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);

    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++){
        c[a[i]]++;
        c[b[i]]--;
    }
    for(int i=0;i<n;i++){
        if(c[a[i]]!=0||c[b[i]]!=0){printf("%d",-1);
        return 0;}
        
    }
    printf("%d",1);
    
    return 0;

}