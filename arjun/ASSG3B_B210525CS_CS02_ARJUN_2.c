#include<stdio.h>
#include<stdlib.h>

int f1=0,f2=0;

int find2(int x,int *arr){
        ++f2;
    if(arr[x]<0){

        return x;
    }
    else if(arr[x]==2000)
         return 0;
    else{
        return find2(arr[x],arr);

    }

}


void makeset(int x,int* arr){
    arr[x]=-1;
}
int find1(int x,int *arr){
   ++f1;
    if(arr[x]<0){
        return x;
    }
    else if(arr[x]==2000)
        return 0;
    else{

        return arr[x]=find1(arr[x],arr);
    }

}
void UNION2(int x,int y,int *arr){
   int a=find2(x,arr);
   int b=find2(y,arr);
     if(a==0||b==0)
    {
        printf("-1 ");
        return;
    }
  if(a==b){

    printf("%d ",a);
  }
  else{
    if(arr[a]>arr[b]){
        arr[a]=b;
        //arr[b]--;
        printf("%d ",b);
    }
    else if (arr[a]==arr[b])
    {   
        arr[b]=a;
        --arr[a];
        printf("%d ",a);
        }
    else
        {
        arr[b]=a;
        //arr[a]--;
        printf("%d ",a);
    }
  }
}

void UNION1(int x,int y,int *arr){
   int a=find2(x,arr);
   int b=find2(y,arr);
   if(a==0||b==0)
    {
        printf("-1 ");
        return;
    }
  if(a==b){
    printf("%d ",a);
  }

        arr[b]=a;
        arr[a]--;
        printf("%d ",a);
}
void UNION4(int x,int y,int *arr){
   int a=find1(x,arr);
   int b=find1(y,arr);
     if(a==0||b==0)
    {
        printf("-1 ");
        return;
    }
  if(a==b){
     
    printf("%d ",a);
  }
  else{
    if(arr[a]>arr[b]){
        arr[a]=b;
        //arr[b]--;
        printf("%d ",b);
    }
    else if (arr[a]==arr[b])
    {   
        arr[b]=a;
        --arr[a];
        printf("%d ",a);
        }
    else
        {
        arr[b]=a;
        //arr[a]--;
        printf("%d ",a);
    }
  }
}

void UNION3(int x,int y,int *arr){
   int a=find1(x,arr);
   int b=find1(y,arr);
   int sum=f1;
   if(a==0||b==0)
    {
        printf("-1 ");
        return;
    }
  if(a==b){
    printf("%d ",a);
  }


        arr[b]=a;
        arr[a]--;
        printf("%d ",a);
    //f1=sum;
}
int main(){

    int treearr1[10000]={0};
    int treearr2[10000]={0};
    int treearr3[10000]={0};
    int treearr4[10000]={0};

    for(int i=0;i<10000;++i){
        treearr1[i]=2000;
        treearr2[i]=2000;
        treearr3[i]=2000;
        treearr4[i]=2000;
    }

    int x,y;
    char a;
    int num1=0,num2=0,num3=0,num4=0;
    f1=0,f2=0;

     while(a!='s'){
        scanf("%c",&a);
        switch(a){
        case 'm':scanf("%d",&x);
                 if(treearr1[x]<0)
                    break;
                 else 
                    printf("%d\n",x);
                 makeset(x,treearr1);
                 //num1++;
                 makeset(x,treearr2);
                 //num2++;
                 makeset(x,treearr3);
                 //num3++;
                 makeset(x,treearr4);
                 //num4++;
                 break;
        
        case 'f':scanf("%d",&x);
                 y=find2(x,treearr1);
                 num1+=f2;
                 f2=0;
                 if(y==0)
                    printf("-1 ");
                else printf("%d ",y);
                 
                 y=find2(x,treearr2);
                 if(y==0)
                    printf("-1 ");
                else printf("%d ",y);
                 num2+=f2;
                 f2=0;
                 y=find1(x,treearr3);
                 num3+=f1;
                 if(y==0)
                    printf("-1 ");
                else printf("%d ",y);
                 f1=0;
                 y=find1(x,treearr4);
                 num4+=f1;
                 if(y==0)
                    printf("-1\n");
                else printf("%d\n",y);
                 f1=0;
                 break;
        case 'u':scanf("%d %d",&x,&y);
                 UNION1(x,y,treearr1);
                 num1+=f2;
                 f2=0;
                 UNION2(x,y,treearr2);
                 num2+=f2;
                 f2=0;
                 UNION3(x,y,treearr3);
                 num3+=f1;
                 f1=0;
                 UNION4(x,y,treearr4); 
                 num4+=f1;
                 f1=0;   
                 printf("\n");
                break;
        case 's':
                 printf("%d %d %d %d\n",num1,num2,num3,num4);
                 break; 
        
        }

     }
     return 0; 
}