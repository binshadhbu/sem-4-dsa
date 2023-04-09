#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *sib;
    struct node *p;
    struct node *child;
    int degree;
};
typedef struct node *node;

struct heap
{
    node head;
};
typedef struct heap* heap;

heap makeheap()
{
    heap h = (heap)malloc(sizeof(struct heap));
    h->head = NULL;
    return h;
}

void binomial_link(node x, node y)
{
    x->p = y;
    x->sib = y->child;
    y->child = x;
    y->degree = y->degree + 1;
}

node createnode(int key)
{
    node temp = (node)malloc(sizeof(struct node));
    temp->child = NULL;
    temp->degree = 0;
    temp->key = key;
    temp->p = NULL;
    return temp;
}
heap heap_merge(heap H1, heap H2)
{
    heap H = makeheap();

    node y = H1->head;
    node z = H2->head;
    if (y != NULL)
    {
        
        if (z != NULL && y->degree > z->degree)
        {
            H->head = z;
            z = z->sib;
        }
        else
        {
            H->head = y;
            y = y->sib;
        }
    }
    else
    {
        H->head = z;
        z = z->sib;
    }
    node x = H->head;
    
    while (y != NULL && z != NULL)
    {
        /* code */
        if (y->degree <=z->degree)
        {
            x->sib = y;
            x = y;
            y = y->sib;
        }
        else
        {
            x->sib = z;
            x = z;
            z = z->sib;
        }
    }
    if (y == NULL)
    {
        x->sib = z;
    }
    else
    {
        x->sib = y;
    }
    
    return H;
}

heap Union(heap h1,heap h2){
    heap h=makeheap();
    h=heap_merge(h1,h2);
    if (h->head==NULL)
    {
        return h;
        /* code */
    }
    
    node x_prev=NULL;
    node x=h->head;
    node x_next=x->sib;
    
    while (x_next!=NULL)
    {
        /* code */
        if((x->degree!=x_next->degree)||(x_next->sib!=NULL&&x_next->sib->degree==x->degree)){
            x_prev=x;
            x=x_next;


        }
        else if(x->key<=x_next->key){
            x->sib=x_next->sib;
            
            binomial_link(x_next,x);
            
        }
        else {
            if(x_prev==NULL){
                h->head=x_next;

            }
            else{
                x_prev->sib=x_next;
                
            }
            binomial_link(x,x_next);
            x=x_next;
            //printf("hi");
        }
        x_next=x->sib;

    }
    x=h->head;
           
    return h;
    
    
}
heap insert(heap h,int k){
    heap h1=makeheap();
    node x=createnode(k);
    h1->head=x;
    h=Union(h,h1);
    return h;
}

node minimum(heap h){
    node y=NULL;
    node x=h->head;
    int min=1000;
    while (x!=NULL)
    {
        if (x->key<min)
        {
            /* code */
            min=x->key;
            y=x;
        }
        x=x->sib;

        
    }
    return y;
    
}
node extractmin(heap h){
    node x=minimum(h);
    // printf("%d\n",x->key);
    
    node ptr=h->head;
    node y=NULL;
    
    while (ptr->key!=x->key)
    {
        y=ptr;
        ptr=ptr->sib;
    }
    if (y==NULL)
    {
        h->head=ptr->sib;
    }
    else
    {
        y->sib=ptr->sib;
    }
    heap h2=makeheap();
    node temp=NULL;
    node next=ptr->child;
    next->p=NULL;
    while (next!=NULL)
    {
        node a=next->sib;
        next->sib=temp;
        temp=next;
        next=a;
        

        /* code */
    }
    h2->head=temp;
    heap z=Union(h,h2);
    h->head=z->head;
    return x;
    

    
    
    
    
}
node find_node(node x, int k) {
    node p = NULL;
    if (x->key == k) {
        p = x;
        return p;
    }
    if (x->child != NULL && p == NULL) {
        p = find_node(x->child, k);
    }
 
    if (x->sib!= NULL && p == NULL) {
        p = find_node(x->sib, k);
    }
    return p;
}

int decreasekey(heap h,int x,int k){
    if (k>x)
    {
        
        return -1;
    }
    
    node temp=find_node(h->head,x);
    if (temp==NULL)
    {
        /* code */
        
        return -1;
    }
    
    
    temp->key=k;
    node y=temp;
    node z=y->p;
    while (z!=NULL&&y->key<z->key)
    {
        int val=y->key;
        y->key=z->key;
        z->key=val;
        y=z;
        z=z->p;
        
        /* code */
    }
    return k;
    
    
}
void delete(heap h,int x){
    node temp=find_node(h->head,x);
    if(temp==NULL){
        printf("-1\n");
        return;
    }
    printf("%d\n",temp->key);
    decreasekey(h,x,-1000);
    extractmin(h);
}
int main()
{
    heap h1 = makeheap();
    heap h2 = makeheap();
    char c;
    int x,k;
   
    while (1)
    {
         scanf("%c",&c);
        if (c=='e')
        {
            /* code */
            return 1;
        }
        if (c=='i')
        {
            
            scanf("%d",&k);
            /* code */
            h1=insert(h1,k);
            //printf("hi");
        }
        if (c=='j')
        {
            
            scanf("%d",&k);
            /* code */
            h2=insert(h2,k);
            //printf("hi");
        }
       
        if (c=='p')
        
        {
             scanf("%d",&k);
            if (k==2)
        {
            /* code */
             node x=h2->head;
             while ((x!=NULL))
                {
                    /* code */
                    printf("%d ",x->key);
                    x=x->sib;
                }
        }
        if (k==1)
        {
            /* code */
             node x=h1->head;
             while ((x!=NULL))
                {
                    /* code */
                    printf("%d ",x->key);
                    x=x->sib;
                }
        }
        printf("\n");
        

         
        }
        if (c=='m')
        {
            node x=minimum(h1);
            printf("%d\n",x->key);
        }
        if (c=='x')
        {
            node x=extractmin(h1);
            printf("%d\n",x->key);
            /* code */
        }
        if (c=='r')
        {
            scanf("%d",&x);
            scanf("%d",&k);
            k=decreasekey(h1,x,k);
            printf("%d\n",k);
            /* code */
        }
        if (c=='d')
        {
            scanf("%d",&k);
            delete(h1,k);
            /* code */
        }
        if (c=='u')
        {
            heap H=makeheap();
            H=Union(h1,h2);
            node x=H->head;
             while ((x!=NULL))
                {
                    /* code */
                    printf("%d ",x->key);
                    x=x->sib;
                }
                printf("\n");
        }
        
            /* code */
        if (c=='e')
        {
            return -1;
        }
  
    }
    
}
