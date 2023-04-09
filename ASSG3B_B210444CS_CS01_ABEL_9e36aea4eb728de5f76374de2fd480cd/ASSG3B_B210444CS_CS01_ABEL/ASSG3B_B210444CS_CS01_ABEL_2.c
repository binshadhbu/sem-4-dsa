#include<stdio.h>
#include<stdlib.h>

struct node1
{
    int key;
    struct node1* p;
    struct node1* rep;
    int rank;

};
typedef struct node1* node1;
int* count1;
int* count2;
int* count3;
int* count4;
node1 create_node(int k){
    node1 temp=(node1)malloc(sizeof(struct node1));
    temp->key=k;
    temp->p=NULL;
    temp->rank=0;
   
}

void makeset1(node1 temp){
    
    temp->p=temp;
    

}
node1 findset1(node1 x,int *count){
    *count=*count+1;
    if (x==x->p)
    {
        return x;
        
        /* code */
    }
    return findset1(x->p,count);
    
    
}
node1 findset2(node1 x,int *count){
    *count=*count+1;
    if (x==x->p)
    {
        return x;
        
        /* code */
    }
    else{
        x->p=findset2(x->p,count);
        return x->p;
    }   
    
}
void link(node1 a,node1 b){
    b->p=a;
}
node1 link_r(node1 a,node1 b){
    if (a->rank<b->rank)
    {
        a->p=b;
        return b;
        /* code */
    }
    else{
        b->p=a;
        if (a->rank==b->rank)
        {
            a->rank=a->rank+1;
        }
        return a;
        

    }
    
    
}
void Union(node1 a,node1 b){
    node1 x=findset1(a,count1);
    node1 y=findset1(b,count1);
    if (x==y)
    {
        printf("%d",x->key);
    }
    link(x,y);
    printf("%d",x->key);
}

void Union2(node1 a,node1 b){
    node1 x=findset1(a,count2);
    node1 y=findset1(b,count2);
    if (x==y)
    {
        printf("%d",x->key);
    }
    x=link_r(x,y);
    printf("%d",x->key);

}
void Union3(node1 a,node1 b){
    node1 x=findset2(a,count3);
    node1 y=findset2(b,count3);
    if (x==y)
    {
        printf("%d",x->key);
    }
    link(x,y);
    printf("%d",x->key);
}
void Union4(node1 a,node1 b){
    node1 x=findset2(a,count4);
    node1 y=findset2(b,count4);
    if (x==y)
    {
        printf("%d",x->key);
    }
    x=link_r(x,y);
    printf("%d",x->key);
}

int main(){
    int a=0;
    int b=0;
    int d=0;
    int e=0;
    count1=&a;
    count2=&b;
    count3=&d;
    count4=&e;
    node1 arr1[10000];
    node1 arr2[10000];
    node1 arr3[10000];
    node1 arr4[10000];
    int k,u;
    char c;
    while (1)
    {
        /* code */
        scanf("%c",&c);
        if (c=='m')
        {
            scanf("%d",&k);
            if (arr1[k]!=NULL)
            {
                printf("-1\n");
                /* code */
            }
            else
            {
                node1 x=create_node(k);
                makeset1(x);
                arr1[k]=x;
                node1 y=create_node(k);
                makeset1(y);
                arr2[k]=y;
                node1 z=create_node(k);
                makeset1(z);
                arr3[k]=z;
                node1 w=create_node(k);
                makeset1(w);
                arr4[k]=w;
                printf("%d",w->key);
                printf("\n");
                /* code */
            }
            
            
            
            /* code */
        }
        if (c=='f')
        {
            scanf("%d",&k);
            if (arr1[k]==NULL)
            {
                printf("-1\n");
                /* code */
            }
            else
            {
                /* code */
                node1 x=findset1(arr1[k],count1);
                printf("%d ",x->key);
                x=findset1(arr2[k],count2);
                printf("%d ",x->key);
                x=findset2(arr3[k],count3);
                printf("%d ",x->key);
                x=findset2(arr4[k],count4);
                printf("%d",x->key);
                printf("\n");
            }
            
            
            

            /* code */
        }
        if (c=='u')
        {
            scanf("%d",&k);
            scanf("%d",&u);
            if(arr1[k]==NULL||arr1[u]==NULL){
                printf("-1\n");
               // printf("hi");
            }
            else{
                Union(arr1[k],arr1[u]);
                printf(" ");
                Union2(arr2[k],arr2[u]);
                printf(" ");
                Union3(arr3[k],arr3[u]);
                printf(" ");
                Union4(arr4[k],arr4[u]);
                printf(" ");
                printf("\n");
            }
            /* code */
        }
        if (c=='s')
        {
            printf("%d %d %d %d",*count1,*count2,*count3,*count4);
            /* code */
        }
    
        
    }
    
}