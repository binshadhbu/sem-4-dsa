#include<stdio.h>
#include<stdlib.h>
struct node
{
    /* data */
    struct node* next;
    
    int key;
    char c;
};
typedef struct node* node;
struct ll
{
   node root;
};
typedef struct ll* ll;
struct queue{
    node elem[1000];
    int head;
    int tail;
};
typedef struct queue* queue;
void enqueue(queue q,node ptr){
    q->elem[q->tail]=ptr;
    q->tail=q->tail+1;
    
    
}
node dequeue(queue q){
    node temp=q->elem[q->head];
    q->head=q->head+1;
    return temp;
}
node create_node(int key){
    node temp=(node)malloc(sizeof(struct node));
    temp->key=key;
  
    temp->next=NULL;
}
void inititalize(ll arr[10000]){
    
    for (int i = 0; i < 10000; i++)
    {
        ll link=(ll)malloc(sizeof(struct ll));
        link->root=NULL;
        /* code */
        arr[i]=link;
    }
    
}
void dfs_visit(ll arr[10000],node u){
    u->c='g';
    printf("%d ",u->key);
    node v=u->next;
    while (v!=NULL)
    {
        /* code */
        node v_real=arr[v->key]->root;
        if (v_real->c=='w')
        {
            /* code */
            dfs_visit(arr,v_real);
        }
        v=v->next;
        
    }
    u->c='b';

    
}
void dfs(ll arr[10000]){
    
    for (int  i = 0; arr[i]->root!=NULL; i++)
    {
        node u=arr[i]->root;
        u->c='w';
        /* code */
    }
    for (int  i = 0; arr[i]->root!=NULL; i++)
    {
        node u=arr[i]->root;
        if (u->c=='w')
        {
            /* code */
            dfs_visit(arr,u);
        }
        
        /* code */
    }
}
    

int main(){
    int k;
    char str[10000];
    ll arr[10000];
    inititalize(arr);
    scanf("%d\n",&k);
    int numc;
    for (int i = 0; i < k; i++)
    {
        /* code */
        fgets(str,10000,stdin);
        int j=0;
        numc=0;
        while (str[j]!='\0')
        {
            /* code */
            numc=0;
            while (str[j]!=' '&&str[j]!='\n')
            {
                numc=numc*10+(str[j]-'0');
                j++;
                /* code */
            }
            j++;
           // printf("%d ",numc);
            node x=create_node(numc);
            ll link=arr[i];
            node ptr=link->root;
            if (ptr==NULL)
            {
                link->root=x;
                
                /* code */
            }
            else
            {
                 while (ptr->next!=NULL)
                {
                    /* code */
                    ptr=ptr->next;
                }
                ptr->next=x;
                /* code */
            }
            
           
            
            
            
        }
     
        
        
        
        
        
        


    }
    dfs(arr);
    
    
}