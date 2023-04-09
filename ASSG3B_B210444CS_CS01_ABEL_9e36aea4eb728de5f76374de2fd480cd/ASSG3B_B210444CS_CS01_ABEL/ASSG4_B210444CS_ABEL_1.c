#include<stdio.h>
int main(){
    int k,x;
    scanf("%d",&k);
    int arr[5][5];
    for (int i = 0; i < k; i++)
    {
        
        for (int j = 0; j < k; j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
    for (int i = 0; i < k; i++)
    {
        /* code */
        printf("%d ",i);
        
        for (int j = 0; j < k; j++)
        {
           if (arr[i][j]==1)
           {
            /* code */
            printf("%d ",j);
           }
            
        }
        printf("\n");
        
    }
    
}