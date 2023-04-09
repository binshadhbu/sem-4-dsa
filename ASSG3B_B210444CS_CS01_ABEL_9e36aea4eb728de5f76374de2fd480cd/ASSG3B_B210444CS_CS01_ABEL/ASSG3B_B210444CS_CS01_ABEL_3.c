#include<stdio.h>
#include<stdlib.h>

struct node1
{
    int key;
    struct node1* p;
    

};
typedef struct node1* node1;
node1 create_node(int k){
    node1 temp=(node1)malloc(sizeof(struct node1));
    temp->key=k;
    temp->p=NULL;
   
   
}

void makeset1(node1 temp){
    
    temp->p=temp;
    

}
node1 findset1(node1 x){
    
    if (x==x->p)
    {
        return x;
        
        /* code */
    }
    return findset1(x->p);
    
    
}
void link(node1 a,node1 b){
    b->p=a;
}
void Union(node1 a,node1 b){
    node1 x=findset1(a);
    node1 y=findset1(b);
    // if (x==y)
    // {
    //     printf("%d",x->key);
    // }
    link(x,y);
    //printf("%d",x->key);
}
void initialize(node1 arr[10000]){
    for (int i = 0; i < 10000; i++)
    {
        arr[i]=NULL;
        /* code */
    }
    
}
int main(){
    node1 arr[10000];
    initialize(arr);
    char c;
    int k,u;
    while(1){
        scanf("%c",&c);
        if(c=='t'){
            scanf("%d",&k);
            scanf("%d",&u);
            node1 x1,x2;
            if (arr[k]==NULL)
            {
                node1 x1=create_node(k);
                makeset1(x1);
                arr[k]=x1;
                /* code */
            }
             if (arr[u]==NULL)
            {
                node1 x1=create_node(u);
                makeset1(x1);
                arr[u]=x1;
                /* code */
            }
            Union(arr[k],arr[u]);

            
            

        }
        
        if (c=='T')
        {
            
            int count=0;
            for (int i = 0; i < 10000; i++)
            {
                if (arr[i]!=NULL&&arr[i]->p==arr[i])
                {
                    
                    count++;
                    /* code */
                }
                
                /* code */
            }
            printf("%d\n",count);
            
            /* code */
        }
        if (c=='d')
        {
            /* code */
            int count=0;
            for (int i = 0; i < 10000; i++)
            {
                /* code */
                if (arr[i]!=NULL)
                {
                    /* code */
                    for (int j = i; j<10000 ; j++)
                {
                    /* code */
                     if (arr[j]!=NULL&&(findset1(arr[i])!=findset1(arr[j])))
                    {
                    
                        count++;
                    /* code */
                    }
                }
                }
                
                
                
            }
            if (count==0)
            {
                printf("-1\n");
            }

            
            else printf("%d\n",count);

            
        }
        if (c=='v')
        {
            scanf("%d",&k);
            scanf("%d",&u);
            if (arr[k]!=NULL&&arr[u]!=NULL&&k<u&&findset1(arr[k])!=findset1(arr[u]))
            {
                /* code */
                printf("1\n");
                
            }
            else printf("-1\n");
            
            /* code */
        }
        if (c=='e')
        {
            break;
            /* code */
        }
        
        
        
        

    }
}