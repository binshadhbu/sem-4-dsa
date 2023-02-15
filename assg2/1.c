#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
struct Node{
    char * name;
    char *roll;
    int age;
    struct Node * next;
};
typedef struct Node node;

struct stack{
    node * gps[4];
    node * heads[4];
};
typedef struct stack st;

node * create(char * name,char * roll,int age){
    node * root=NULL;
    strcpy(root->name,*name);
    strcpy(root->roll,*roll);
    root->age=age;
    root->next;
    return root;
}

void insert(st * groups,node * root,int index){
    


}

int find_gp(char * name,int age){
    int i=0;
    int val=0;
    int ch=0;
    while(*name[i++]){
        ch=*name[i];
        val+=ch;
    }
    val=val+age;
    val%=4;
    return val;
}
int main(){
    int n;
    scanf("%d",&n);
    char *name[n],*roll[n];
    int a[n];
    int ascii[n];
    for(int i=0;i<;i++){
        scanf("%s%s%d",name[i],roll[i],a[i]);
        ascii[i]=find_gp(name[i],age[i]);
    }
    st *grps=NULL;
}