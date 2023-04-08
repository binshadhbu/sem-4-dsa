#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int val,weight;
    struct Node * next;

};
typedef struct Node node;
node * create_edge(int val){
    node *t=(node *)malloc(sizeof(node));
    t->val=val;
    t->weight=0;
    t->next=NULL;
    return t;
}
int min_edge1(node **list,int n,int *visit){
    node *y=NULL;
    int u,v,dist=100000;
    for(int i=0;i<n;i++){
        if(visit[i]==1){
            y=list[i];
            while(y){
                if(dist>y->weight&&visit[y->val]!=1){
                    v=y->val;
                    dist=y->weight;
                }
                y=y->next;
            }
        }
    }
    visit[v]=1;
    return dist;
}
int prim(node **list,int n){
    int ans=0;
    int * visit=(int*)malloc(n*sizeof(int ));
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
    visit[0]=1;
    for(int i=0;i<n-1;i++){
        ans=ans+min_edge1(list,n,visit);
    }
    return ans;
}
int min_edge2(node **list,int n,int *component){
    node *y=NULL;
    int u,v,dist=100000;
    for(int i=0;i<n;i++){
        y=list[i];
        while(y){
            if(dist>y->weight&&component[i]!=component[y->val]){
                u=i;
                v=y->val;
                dist=y->weight;
            }
            y=y->next;
        }
    }
    int d=component[v];
    for(int i=0;i<n;i++){
        if(component[i]==d){
            component[i]=component[u];
        }
    }
    return dist;

}


int kruskal(node **list,int n){
    int *component=(int *)malloc(n*sizeof(int));
    int ans=0;
    for(int i=0;i<n;i++){
        component[i]=i;
    }
    for(int i=0;i<n-1;i++){
        ans=ans+min_edge2(list,n,component);
    }
    return ans;
}
int main(){
    const int size=1000;
    char c;
    int n,u,v;
    scanf("%c",&c);
    scanf("%d\n",&n);
    char *str=(char *)malloc(size*sizeof(char));
    node **list=(node **)malloc(n*sizeof(node *));
    for(int i=0; i<n;i++){
        list[i]=NULL;
    }
    node * x;
    node * y;
    for(int i=0; i<n; i++){
        fgets(str,size,stdin);
        u=0;v=0;
        for(u=0;u<strlen(str)-1;u++){
            if(str[u]==' '){
                if(v!=i){
                    x=create_edge(v);
                    y=list[i];
                    if(y==NULL){
                        list[i]=x;
                    }else{
                        while(y->next)y=y->next;
                        y->next=x;
                    }
                }
                v=0;
            }else{
                v=v*10+str[u]-'0';
            }
        }
        if(v!=i){
            x=create_edge(v);
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

    for(int i=0;i<n;i++){
        scanf("%d",&u);
        y=list[u];
        while(y!=NULL){
            scanf("%d",&v);
            y->weight=y->weight+v;
            y=y->next;
        }
    }
    switch(c){
        case 'a':
        printf("%d\n",prim(list,n));
        break;
        case 'b':
        printf("%d\n",kruskal(list,n));
        break;
    }
    return 0;
    
}

