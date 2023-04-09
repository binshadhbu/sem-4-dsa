#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    int val,weight;
    struct Node * next;
};
typedef struct Node node;
node * create(int val){
    node *x=(node *)malloc(sizeof(node ));

    x->val=val;
    x->weight=0;
    x->next=NULL;
    return x;
}
int find_min(int *dist,int *visit,int n){
    int min=10000000,ind=0;
    for(int i=0;i<n;i++){
        if(dist[i]<min&&visit[i]==0){
            min=dist[i];
            ind=i;
        }
    }
    return ind;
}
void dijkstra1(node **list,int u,int n){
    int a;
    int *visit=(int *)malloc(n*sizeof(int));
    int *dist=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        visit[i]=0;
        dist[i]=100000000;
    }
    dist[u]=0;
    for(int i=0;i<n;i++){
        a=find_min(dist,visit,n);
        visit[a]=1;
        node *y=list[a];
        while(y){
            if(dist[y->val]>dist[a]+y->weight)
            dist[y->val]=dist[a]+y->weight;
        }
        y=y->next;
    }
    for(int i=0;i<n;i++){
        if(dist[i]==100000000)
        printf("INF ");
        else printf("%d ",dist[i]);
    }
    printf("\n");
    
}
void dijkstra2(node **list,int u,int v,int n){
    int *visit=(int *)malloc(n*sizeof(int));
    int * dist=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        visit[i]=0;
        dist[i]=100000000;
    }
    dist[u]=0;
    for(int i=0;i<n;i++){
        int a=find_min(dist,visit,n);
        visit[a]=1;
        node * y=list[a];
        while(y){
        if(dist[y->val]>dist[a]+y->weight){
            dist[y->val]=dist[y->val]+y->weight;
        }
        y=y->next;
        }
        
    }
    if(dist[v]==100000000)printf("UNREACHABLE\n");
    else printf("%d\n",dist[v]);
}
int main(){
    int n,u,v;
    scanf("%d",&n);
    scanf("\n");
    char *str=(char *)malloc(1000*sizeof(char ));
    node **list=(node **)malloc(n*sizeof(node *));
    for(int i=0;i<n;i++){
        list[i]=NULL;
    }
    node *x;
    node *y;
    for(int i=0;i<n;i++){
        fgets(str,1000,stdin);
        u=0;v=0;
        for(u=0;u<strlen(str)-1;u++){
            if(str[u]==' '){
                if(v!=i){
                    x=create(v);
                    y=list[i];
                    if(!y){
                        list[i]=x;

                    }else{
                        while(y->next){
                            y=y->next;
                        }
                        y->next=x;
                    }
                }
                v=0;
            }else
                v=v*10+(str[u]-'0');
        }
        if(v!=i){
        x=create(v);
        y=list[i];
        if(!y){
            list[i]=x;
        }else{
            while(y->next)
            y=y->next;
            y->next=x;
        }
    }
    
    }
    for(int i=0;i<n;i++){
        scanf("%d",&u);
        y=list[u];
        while(y){
            scanf("%d",&v);
            y->weight+=v;
            y=y->next;
        }
    }
    while(1){
        str=(char*)malloc(sizeof(char)*50);
        scanf("%s",str);
        if(strcmp(str,"apsp")==0){
            scanf("%d",&u);
            dijkstra1(list,n,u);
        }else if(strcmp(str,"sssp")==0){
            scanf("%d %d",&u,&v);
            dijkstra2(list,u,v,n);
        }else if(strcmp(str,"stop")==0)return 0;
    }
    
}