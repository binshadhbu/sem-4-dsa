#include<stdio.h>
#include<stdlib.h>

struct queue{
int head;
int tail;
int arr[10000];
};
struct queue *createqueue(){
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    q->head=0;
    q->tail=0;
    return q;
}
void enqueue(struct queue *q,int x){
    q->arr[q->tail]=x;
    q->tail=q->tail+1;
}
int dequeue(struct queue *q){
    int temp;
    temp=q->arr[q->head];
    q->head=q->head+1;
    return temp;
}


int main(){
    int nod;
    scanf("%d",&nod);

    struct queue *Q;
    Q=createqueue();
    int visited[1000]={0};

    int i,j,x;
    char a;
    int graph[1000][500]={0};
    for(i=0;i<nod;++i){
        j=0;
        a='a';
        scanf("%*d");
        while(a!='\n'&&a!=-1){
            scanf("%d%c",&x,&a);
            graph[i][x]=1;
        }

    }

    
    enqueue(Q,0);
    visited[0]=1;

    while(Q->head!=Q->tail){
        int ongoing =Q->arr[Q->head];
        
        printf("%d ",ongoing);
        dequeue(Q);

        for(i=0;i<nod;++i){

            if((graph[ongoing][i]==1)&&(visited[i]==0)){
                visited[i]=1;
                enqueue(Q,i);
            }

        }
        //visited[ongoing]=2;
    }
    return 0;
}
