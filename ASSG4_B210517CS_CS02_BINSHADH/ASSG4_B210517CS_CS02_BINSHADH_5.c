

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int val;
    int weight;
    struct Node* next;
};
typedef struct Node node;

node * makeEdge(int v){
    node *x=(node *)malloc(sizeof(node));
    x->val=v;
    x->weight=0;
    x->next=NULL;
    return x;
}

int findMin(int* dist,int* visit, int n){
    int min=10000000,ind=0;
    for(int i=0;i<n;i++){
        if(dist[i]<min&&visit[i]==0){
            min=dist[i];
            ind=i;
        }
    }
    return ind;
}

void dijkstra1(node** list,int u,int n){
    int* visit=(int*)malloc(n*sizeof(int));
    int* dist=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        visit[i]=0;
        dist[i]=10000000;
    }
    dist[u]=0;
    int a;
    for (int i=0;i<n;i++){
        a=findMin(dist,visit,n);
        visit[a]=1;
        node* y=list[a];
        while(y!=NULL){
            if(dist[y->val]>dist[a]+y->weight ){
                dist[y->val]=dist[a]+y->weight;
            }
            y=y->next;
        }
    }
    for (int i=0;i<n;i++){
        if (dist[i]==10000000){
            printf("INF ");
        }else{
            printf("%d ",dist[i]);
        }
    }
    printf("\n");
}

void dijkstra2(node** list,int u,int v,int n){
    int* visit=(int*)malloc(n*sizeof(int));
    int* dist=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        visit[i]=0;
        dist[i]=10000000;
    }
    dist[u]=0;
    int a;
    for (int i=0;i<n;i++){
        a=findMin(dist,visit,n);
        visit[a]=1;
        node * y=list[a];
        while(y!=NULL){
            if(dist[y->val]>dist[a]+y->weight){
                dist[y->val]=dist[a]+y->weight;
            }
            y=y->next;
        }
    }
    if (dist[v]==10000000){
        printf("UNREACHABLE\n");
    }else{
        printf("%d\n",dist[v]);
    }
}

int main(){
    int n,u,v;
    scanf("%d\n",&n);
    char* str;
    node** list=(node**)malloc(n*sizeof(node*));
    for (int i=0;i<n;i++){
        list[i]=NULL;
    }
    node* x,*y;
    for (int i=0;i<n;i++){
        str=(char*)malloc(10000*sizeof(char));
        fgets(str,10000,stdin);
        u=0;
        v=0;
        for(u=0;u<strlen(str)-1;u++){
            if(str[u]==' '){
                if(v!=i){
                    x=makeEdge(v);
                    y=li

#include<stdio.h>
#include<stdlib.h>

void DFS(int);
int G[10][10],num_ver,dfs_visit[10],ver_index[20],bfs_visit[20],forw=0,back=-1;

void BFS(int v)
{
    int i,j;
    for (i=0; i<num_ver; i++)
        if(!bfs_visit[i] && G[v][i])
            ver_index[++back]=i;
    if(forw<=back)
    {
        bfs_visit[ver_index[forw]]=1;
        BFS(ver_index[forw++]);
    }
}
void DFS(int v)
{
    int i;
    printf("%d ",v);
    dfs_visit[v]=1;
    for(i=0; i<num_ver; i++)
    {
        if(!dfs_visit[i]&&G[v][i]==1)
        {
            DFS(i);
        }
        else;
    }
}
int main(){
    int i,j;
    int e,u,v,start;
    scanf("%d",&num_ver);
    for(i=0; i<num_ver; i++)
    {
        for(j=0; j<num_ver; j++)
        {
            G[i][j]=0;
        }
    }
     for(i=0; i<num_ver; i++)
    {
        dfs_visit[i]=0;
    }
    
    for (i=0; i<num_ver; i++)
    {
        ver_index[i]=0;
        bfs_visit[i]=0;
    }
    for(int i=0;i<num_ver;i++){
        char *s=(char *)malloc(100*sizeof(char));
        fgets(s,100,stdin);
        int key=0,mul=1;
        for(int j=2;s[j]!='\0';j++){
            if (s[j] <= '9' && s[j] >= '0')
			{
				key = key + (s[j] - '0');
				mul = mul * 10;
			}
			if (s[j] == ' ')
			{
				G[i][key]=1;
				key = 0;
			}
        }
    }
    DFS(0);

}st[i];
                    if(y==NULL){
                        list[i]=x;
                    }else{
                        while(y->next!=NULL){
                            y=y->next;
                        }
                        y->next=x;
                    }
                }
                v=0;
            }else{
                v=v*10+str[u]-'0';
            }
        }
        if(v!=i){
                x=makeEdge(v);
                y=list[i];
                if(y==NULL){
                    list[i]=x;
                }else{
                    while(y->next!=NULL){
                        y=y->next;
                    }
                    y->next=x;
                }
            }
    }
    for (int i=0;i<n;i++){
        scanf("%d",&u);
        y=list[u];
        while(y!=NULL){
            scanf("%d",&v);
            y->weight+=v;
            y=y->next;
        }
    }
    while (1){
        str=(char*)malloc(20*sizeof(char));
        scanf("%s",str);
        if(strcmp(str,"apsp")==0){
            scanf("%d",&u);
            dijkstra1(list,u,n);
        }else if(strcmp(str,"sssp")==0){
            scanf("%d %d",&u,&v);
            dijkstra2(list,u,v,n);
        }else if(strcmp(str,"stop")==0){
            return 0;
        }
    }
}