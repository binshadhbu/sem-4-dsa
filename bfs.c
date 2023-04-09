#include<stdio.h>
#include<stdlib.h>
struct node
{
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
    return temp;
}
void inititalize(ll arr[10000]){
    
    for (int i = 0; i < 10000; i++)
    {
        ll link=(ll)malloc(sizeof(struct ll));
        link->root=NULL;
        arr[i]=link;
    }
}
void bfs(ll arr[10000]){
    node s=arr[0]->root;
    for (int  i = 1; arr[i]->root!=NULL; i++)
    {
        node u=arr[i]->root;
        u->c='w';
    }
    s->c='g';
    queue q=(queue)malloc(sizeof(struct queue));
    q->head=0;
    q->tail=0;
    enqueue(q,s);
    while (q->head!=q->tail)
    {
        node u=dequeue(q);
        node v=arr[u->key]->root->next;
        while(v!=NULL){
            node v_real=arr[v->key]->root;
            if (v_real->c=='w')
            {
                v_real->c='g';
                enqueue(q,v_real);
            }
            v=v->next;
            
        }
        u->c='b';
        printf("%d ",u->key);
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
          
            }
            j++;
            node x=create_node(numc);
            ll link=arr[i];
            node ptr=link->root;
            if (ptr==NULL)
            {
                link->root=x;
            }
            else
            {
                 while (ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=x;
            }               
        }
    }
    bfs(arr);
}