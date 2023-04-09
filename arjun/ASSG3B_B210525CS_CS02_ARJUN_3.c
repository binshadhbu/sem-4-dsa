#include<stdio.h>
#include<stdlib.h>

void makeset(int x,int* arr){
    arr[x]=-1;
}
int find(int x,int *arr){
 
    if(arr[x]<0){
        //++f1;
        return x;
    }
    else if(arr[x]==0)
        return 0;
    else{
        
        return arr[x]=find(arr[x],arr);
    }

}
void UNION(int x,int y,int *arr){
   int a=find(x,arr);
   int b=find(y,arr);
     if(a==0||b==0)
    {
        //printf("-1 ");
        return;
    }
  if(a==b){
    return; 
    //printf("%d ",a);
  }
  else{
    if(arr[a]>arr[b]){
        arr[b]+=arr[a];
        arr[a]=b;
        
        //printf("%d ",b);
    }
    else if (arr[a]==arr[b])
    {   
        arr[a]+=arr[b];
        arr[b]=a;
        
        //printf("%d ",a);
        }
    else
        {
        arr[a]+=arr[b];
        arr[b]=a;
        
        //printf("%d ",a);
    }
  }
}

int printnum(int *arr,int min,int max){
    int num=0;
    int i;
    for(i=min;i<=max;++i){
         if(arr[i]<0)
            ++num;
    }
    return num;

}
void possiblecombinations(int *arr,int min,int max,int num){
    if(num==0){
        printf("-1\n");
        return;
    }
int array[100];
int i,j=0,l,k;
int sum=0;
for(i=min;i<=max;++i){
        if(arr[i]<0)
            {
                array[j]=-arr[i];
                ++j;
            }
}
for(i=0;i<j;++i){
    k=array[i];
    for(l=i+1;l<j;++l){
       sum+=k*array[l];
    }
}
if(sum==0)
  printf("-1\n");
else
printf("%d\n",sum);
}
void checkifvalid(int x,int y,int *arr){
    if(x>y)
      printf("-1\n");
    else{
        if(find(x,arr)!=find(y,arr))
            printf("1\n");
        else 
            printf("-1\n");
    }
}
int main(){
    int x,y;
    int max=0;
    int min=999;
    int num;
    int arr[1010]={0};
    char a;
    while(a!='e'){
        scanf("%c",&a);
        switch(a){
            case 't':scanf("%d %d",&x,&y);
                     if(arr[x]==0)
                     makeset(x,arr);
                     if(arr[y]==0)
                     makeset(y,arr);
                     if(x>max)
                        max=x;
                     if(x<min)
                        min=x;
                     if(y>max)
                        max=y;
                     if(y<min)
                        min=y;
                     UNION(x,y,arr);
                     break;
            
            case 'T':
                     num=printnum(arr,min,max);
                     printf("%d\n",num);
                     break;
            
            case 'd':
                     num=printnum(arr,min,max);
                     possiblecombinations(arr,min,max,num);
                     break;
            case 'v':scanf("%d %d",&x,&y);
                     checkifvalid(x,y,arr);
                     break;
            case 'e':
                     return 0;
                     break;
                    
        }
    }
return 0;
}