#include<stdio.h>
#include<stdlib.h>

void DFS_visit(int current,int nod,int *arr,int graph[][500] ){
arr[current]=1;
printf("%d ",current);

for(int i=0;i<nod;++i){
    if(graph[current][i]==1&&arr[i]==0){
        DFS_visit(i,nod,arr,graph);
    }
}
arr[current]=2;
}
int main(){
    int nod;
    scanf("%d",&nod);

    struct queue *Q;
    //Q=createqueue();
    int visited[1000]={0};

    int i,j,x;
    char a;
    int graph[1000][500]={0};
    for(i=0;i<nod;++i){
        j=0;
        a='a';
        scanf("%*d");
        while(a!='\n'){
            scanf("%d%c",&x,&a);
            graph[i][x]=1;
        }

    }
    for(i=0;i<nod;++i){
        if(visited[i]==0){
            DFS_visit(i,nod,visited,graph);
        }
    }
    
    printf("\n");

    return 0;

    
}