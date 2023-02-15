#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[100];
    char roll[15];
    int age;
    char branch[2];
    struct Node * next;
};
typedef struct Node node;
struct hash{
    node *g0,*g1,*g2,*g3;
    node * h1,*h2,*h3,*h0;
};
node * create(char name[],char roll[],int age){
    node * root=(node *)malloc(sizeof(node));
    strcpy(root->name,name);
    strcpy(root->roll,roll);
    root->age=age;
    root->next=NULL;
    return root;
}
int hash_function(char name[],int age){
    int value;
    int ascii=0;
    int i=0;
    while(name[i]){
        ascii=name[i++]+ascii;
    }
    value=age+ascii;
    value=value%4;
    return value;
}

void insert(struct hash * table,node *temp,int index){
if((index==0&&table->g0==NULL)||(index==1&&table->g1==NULL)&&(index==2&&table->g2==NULL)&&(index==3&&table->g3==NULL)){
    switch(index){
        case 0:table->g0=table->h0=temp;break;
        case 1:table->g1=table->h1=temp;break;
        case 2:table->g2=table->h2=temp;break;
        case 3:table->g3=table->h3=temp;break;
    }
    return ;
}
node * ne;
 if(index==0){
    temp->next=table->h0;
    table->h0=temp;
 }else if(index==1){
    temp->next=table->h1;
    table->h1=temp;
 }else if(index==2){
    temp->next=table->h2;
    table->h2=temp;
 }else if(index==3){
    temp->next=table->h3;
    table->h3=temp;
 }
}

void create_hash(struct hash * table,char *name[],char *roll[],int age[],int n){
    int i;
    int index=0;
    for (i=0;i<n;i++){
        node * temp=create(*(name+i),*(roll+i),age[i]);
        index=hash_function(*(name+i),age[i]);
        insert(table,temp,index);
    }
    
}

int count(struct hash * table,int index){
    int num=0;
    if(index==0){
        node * t=table->h0;
        if(table->h0==NULL)return 0;
        while(){
            num++;
            
        }
    }
    
}

int main(){
    struct hash * table=(struct hash *)malloc(sizeof(struct hash));
    table->g0=table->g1=table->g2=table->g3=NULL;
    table->h0=table->h1=table->h2=table->h3=NULL;
    int n,k,m;
    char c;
    scanf("%d",&n);
    char *name[n];
    char *roll[n];
    int age[n];
    for(int i=0;i<n;i++){
        scanf("%s%s%d",name[i],roll[i],&age[i]);
    }
    create_hash(table,name,roll,age,n);
    
    
}