#include<stdio.h>
#include<malloc.h>

struct node{
    int val;
    int degree;
    struct node *parent;
    struct node *child;
    struct node *sibling;
};

struct queue{
int head;
int tail;
struct node *arr[1000];
};
struct queue *createqueue(){
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    q->head=0;
    q->tail=0;
    return q;
}
void enqueue(struct queue *q,struct node *x){
    q->arr[q->tail]=x;
    q->tail=q->tail+1;
}
struct node* dequeue(struct queue *q){
    struct node *temp=q->arr[q->head];
    q->head=q->head+1;
    return temp;
}

struct node* createheap(){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    p=NULL;
    return p;
}
void printroot(struct node *H){
    while(H!=NULL){
        printf("%d ",H->val);
        H=H->sibling;
    }
    printf("\n");
}
struct node* createnode(int key){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->val=key;
    temp->parent=NULL;
    temp->child=NULL;
    temp->sibling=NULL;
    temp->degree=0;
    return temp;
}
int link_tree(struct node * y,struct node *z){
    y->parent=z;
    y->sibling=z->child;
    z->child=y;
    z->degree=z->degree+1;
}

struct node *merge_heap(struct node*H1,struct node *H2){
    struct node *H=createheap();
    struct node* y;
    struct node* z;
    struct node* a;
    struct node* b;

    
    
    y=H1;
    z =H2;
    if(y!=NULL){
        if(z!=NULL&&y->degree<=z->degree){
        H=y;
        y=y->sibling;
        }
        else if(z!=NULL&&y->degree>z->degree)
        {
        H=z;
        z=z->sibling;
        }
        else{
        H=y;
        y=y->sibling;
        }
    }else {
      H=z;
      z=z->sibling;
    }
a=H;
    while(y!=NULL&&z!=NULL){
        if(z->degree>=y->degree){
          a->sibling=y;
          y=y->sibling;

        }


        else{
          a->sibling=z;
          z=z->sibling;

        }
        a=a->sibling;
    }
    while(y!=NULL){
        a->sibling=y;
        y=y->sibling;

        
        a=a->sibling;
    }
        while(z!=NULL){
        a->sibling=z;
        z=z->sibling;

        
        a=a->sibling;
    }
    // }
    // else
    //   H=z;
    //   struct node *k=y;
    //   struct node *k1=z;
    //   while(y!=NULL&&z!=NULL){
    //     if(y->degree<z->degree){
    //         if(y->sibling==NULL){
    //             y->sibling=z;
    //             break;
    //         }
    //         y=y->sibling;

    //     }
    //     else if(y->degree==z->degree){
    //         a=y->sibling;
    //         y->sibling=z;
    //         y=a;
    //     }
    //     else {
    //         b=z->sibling;
    //         z->sibling=y;
    //         z=b;
    //     }
    //   }

    return H;
}


struct node* heap_union(struct node* H1,struct node *H2){
    struct node *prev;
    struct node *next;

    struct node *x;
   struct node *H=createheap();
    if(H1==NULL)
      return H2;
    else if(H2== NULL)
        return H1;
        else if(H1==NULL& &H2==NULL)
            return NULL;
    H=merge_heap(H1,H2);
    if(H==NULL)
      return H;
    prev =NULL;
    x=H;
    next=x->sibling;
    while(next!=NULL){
        if((x->degree!=next->degree)||((next->sibling!=NULL)&&next->sibling->degree==x->degree)){
            prev=x;
            x=next;
            next=x->sibling;

        }
        else{
            if(x->val<=next->val){ 
                x->sibling=next->sibling;
                link_tree(next,x);
                next=x->sibling;
            }
             else{
            if(prev==NULL)
              H=next;
            else
              prev->sibling=next;
            link_tree(x,next);
            x=next;
            next=x->sibling;
        }
        }
       
    }
    return H;
}

struct node *heap_insert(struct node *H,struct node *x){
    struct node *H1;
    x->parent=NULL;
    x->child=NULL;
    x->sibling=NULL;
    x->degree=0;
    H1=x;
    H=heap_union(H,H1);
    return H;
}

void display(struct node*H){
    struct node *p;
    if(H==NULL){
        //printf("The heap is empty");
    
    }
    //printf("\nThe root nodes are:-\n");
    p=H;
    while(p!=NULL){
        printf("%d",p->val);
        if(p->sibling!=NULL)
             printf("->");
             p=p->sibling;
    }
    
}
int findmin(struct node* H){
    int min=999;
    struct node *p;
    if(H==NULL){
        //printf("The heap is empty");
        return -1;
    }
    p=H;
    while(p!=NULL){
        if(p->val<min)
            min=p->val;
        p=p->sibling;
    }
    return min;
}
struct node * reverse_heap(struct node *y){
    struct node *x,*z,*k;
    x=y;
    z=NULL;
    k=NULL;
while(x!=NULL){
    k=x->sibling;
    x->sibling=z;

    z=x;
    x=k;
}
return z;
}
struct node *extractmin(struct node **H1){
    int min=(*H1)->val;
    struct node *t=NULL;
    struct node *x=*H1;
    struct node *Hr;
    struct node * p;
    Hr=NULL;
    
    if(x==NULL){
        return x;
    }
    p=x;
    while (p->sibling !=NULL){
        if((p->sibling)->val<min){
            min =(p->sibling)->val;
            t=p;
            x=p->sibling;
        }
        p=p->sibling;
    }

    if(t==NULL && x->sibling==NULL)
       *H1=NULL;
    else if(t==NULL)
       *H1=x->sibling;
    else if(t->sibling == NULL)
       t=NULL;
    else
       t->sibling=x->sibling;
    if(x->child!=NULL){
        Hr=reverse_heap(x->child);
        (x->child)->sibling=NULL;
    }
    *H1=heap_union(*H1,Hr);
    x->child=NULL;

    return x;

}

// struct node* extractmin(struct node* head){//returns head
//      struct node* g=head;
//      struct node* H=head;
//      struct node* min;
//      struct node* p=head;
//     while(head->sibling !=NULL){
//         if(head->sibling->val <g->val){
//         g=head->sibling;
//         p=head;
//         }
//         head=head->sibling;
//     }
//     min =g;
//     printf("min is %d",p->val);
//     if(p==NULL)
//     H=g->sibling;
//     // if(g->sibling=NULL)
//     // p=NULL;
//     // else
//     p->sibling=g->sibling;

//     g=g->child;
//     g=reverse(g);
//     H=heap(g,H);
//     return(H);
// }


struct node * find_node(struct node * H,int k){
struct node *x=H;
struct node *p=NULL;
if(x->val==k){
    p=x;
    return p;
}
if(x->child!=NULL&&p==NULL){
    p=find_node(x->child,k);
}
if(x->sibling!=NULL&&p==NULL){
    p=find_node(x->sibling,k);
}
return p;
}

int decrease_key(struct node *H,int i,int k){
    struct node *p;
    struct node *y;
    struct node *z;
    if(H==NULL){
        //printf("The heap is empty");
        printf("-1\n");
        return -1;
    }
    p=find_node(H,i);
    if(p==NULL){
        //printf("The element is not present in the heap");
        printf("-1\n");
        return -1;
    }
    if(k>p->val){
        //printf("The new key is greater than the current key");
        printf("-1\n");
        return -1;
    }
    //printf("%d\n",k);
    p->val=k;
    y=p;
    z=p->parent;
    while(z!=NULL&&y->val<z->val){
        int temp;
        temp=y->val;
        y->val=z->val;
        z->val=temp;
        y=z;
        z=z->parent;
    }
    return 1;
}
void levelhelper(struct queue *q,int i){
    struct node *p;
    struct queue *q1=createqueue();
    int j=0;
    if(i==0)
     return;
    while(i!=0){
       p=dequeue(q);
         if(p->child!=NULL){
               ++j;
               enqueue(q1,p->child);
         }
        while(p!=NULL){
            printf("%d ",p->val);
            p=p->sibling;
        }
        --i;
    }
    levelhelper(q1,j);
}
void levelorder(struct node *H){
    struct node *p;
    int i=0;
    struct queue *q=createqueue();
    
    if(H==NULL){
        printf("The heap is empty");
        return;
    }
    p=H;
    while(p!=NULL){
        printf("%d ",p->val);
        if(p->child!=NULL){
            ++i;
            enqueue(q,p->child);
        }
           
        
        p=p->sibling;
    }
    levelhelper(q,i);

}
struct node* heap_delete(struct node *H,int k){
    struct node *np;
    if(H==NULL){
        //printf("The heap is empty");
        return H;
    }
    decrease_key(H,k,-1000);
    printf("%d\n",k);
    np=extractmin(&H);
    H->parent=NULL;
    // if(np!=NULL){
    //     free(np);
    //     //printf("The node is deleted");
    // }
        
    return H;
}

int main(){
   int i,n,m,l;
   int key;
   int k;
   struct node *H;
   struct node* p;
   struct node* np;
   struct node* x;
   char ch;
    struct node *H1=createheap();
    struct node *H2=createheap();

    while(ch!='e'){
        scanf("%c",&ch);
        switch(ch){
            case 'i':
             scanf("%d",&n);
                p=createnode(n);
                H1=heap_insert(H1,p);
                break;
            case 'j':
                scanf("%d",&n);
                p=createnode(n);
                H2=heap_insert(H2,p);
                break;
            case 'd':
                scanf("%d",&n);
                H1=heap_delete(H1,n);
                break;
            case 'p':
                scanf("%d",&n);
                if(n==1)
                printroot(H1);
                //levelorder(H1);
                else
                printroot(H2);
                //levelorder(H2);
                break;
            case 'x':
                x=extractmin(&H1);
                np=H1;
                H1->parent=NULL;
                printf("%d\n",x->val);
                //free(x);
                break;
            case 'm':
                key=findmin(H1);
                printf("%d\n",key);
                break;
            case 'r':
                scanf("%d %d",&n,&m);
                k=decrease_key(H1,n,m);
                if(k==1)
                   printf("%d\n",m);
                 break;
            case 'u':
                H=heap_union(H1,H2);
                printroot(H);
                //levelorder(H);
                break;
            case 'e':
                return 0;
                break;
        }
    }
    return 0;
}