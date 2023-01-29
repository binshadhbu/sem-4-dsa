#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    int val;
    struct Node * left,*right,*parent;
};
typedef struct Node node;
void print(node * root){
    if(root==NULL)
    return ;
    printf("%d ",root->val);
    print(root->left);
    print(root->right);
}

node * built(char * str){
    int key,temp,i;
    str+=2;
    if(*str==')')
    return NULL;
    char k[1000];
    i=0;
    while((*str<='9'&&*str>='0')||*str=='-'){
        k[i++]=*str++;
    }
    k[i]='\0';
    key=atoi(k);
    node *root=(node *)malloc(sizeof(node));
    root->val=key;
    str++;
    root->left=built(str);
    node * ne=NULL;
    if(root->left){
        ne=root->left;
        ne->parent=root;
    }
    str++;
    temp=1;
    while(temp!=0){
        if(*str=='(')temp++;
        if(*str==')')temp--;
        str++;
    }
    str++;
    node * right=(node *)malloc(sizeof(node));
    right=built(str);
    root->right=right;
    if(root->right){
        ne=root->right;
        ne->parent=root;
    }
    return root;
}


int main(){
    node * root=NULL;
    char * str=(char *)malloc(sizeof(char)*1000);
    scanf("%[^\n]s",str);
    root=built(str);
    int count=0;
    countgp(root,&count);
    printf("%d\n",count);
    return 0;
}