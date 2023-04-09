#include<stdio.h>
#include<stdlib.h>
void dfs(int current,int node,int *arr,int graph[][500]){
    arr[current]=1;
    printf("%d ",current);
    for(int i=0;i<node;++i){
        if(graph[current][i]==1&&arr[i]==0){
            dfs(i,node,arr,graph);
        }
    }
    arr[current]=2;
}
int main(){
    int n;
    scanf("%d",&n);
    int visited[1000]={0};
    int i,j,x,graph[1000][500]={0};
    char a='a';
    for(int i=0;i<n;i++){
        j=0;
        a='a';
        scanf("%*d");
        while(a!=='\n'){
            scanf("%d%c",&x,&a);
            graph[i][x]=1;
        }
    }
    for(i=0;i<n;i++){
        dfs(i,n,visited,graph);
    }
}