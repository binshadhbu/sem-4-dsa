#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

struct Node{
    int val;
    struct Node *left,*right,*parent;
} ;
typedef struct Node  node;
node * create(int k){
    node * t=(node *)malloc(sizeof(node));
    t->left=t->right=t->parent=NULL;
    t->val=k;
    return t;
}
void  insert(node ** root,int k){
    node * t=(node *)malloc(sizeof(node));
    t=create(k);
    node *p,*q;
    q=NULL;
    p=*root;
    if(*root==NULL){
        t->val=k;
        *root=t;
        return ;
    }
    else{
        while(p!=NULL){
            q=p;
            if(k>p->val)p=p->right;
            else p=p->left;
        }
        if(q){
            t->parent=q;
            if(k>q->val)q->right=t;
        else q->left=t;
        }
    }
}
node * search(node * root,int k){
    if(!root)return NULL;
    while(root){
        if(root->val==k)return root;
        else if(root->val>k){
            search(root->left,k);
        }else{
            search(root->right,k);
        }
    }
    return NULL;
}
node * minimum(node * root){
    while(root->left){
        root=root->left
    }
    return root;

}
node * suc(node * root,int k){
    node * present=search(root,k);
    if(!present){
        return NULL;
    }
    if(present->right){
        return minimum(present->right);
    }
    node * p=present->parent;
    while(p&&present==p->right){
        present=p;
        p=p->parent;
    }
    return p;
}
node * delete(node * root,int k){
    if(root==NULL)return NULL;
    if(k<root->val){
        root->left=delete(root->left,k);
    }else if(k>root->val){
        root->right=delete(root->right,k);
    }else{
        if(root->left==NULL){
            node *temp=root->right;
            free(root);
            return temp;
        }
        else{
            node * temp=root->left;
            free(root);
            return temp;
        }
        node * temp=minimum(root->right);
        root->val=temp->val;
        root->right=delete(root->right,temp->key);
    }
    return root;
}
void print(node * root){
    if(root==NULL)return ;
    printf("%d ",root->val);
    print(root->left);
    print(root->right);
}
int main(){
    node * root=NULL;
    int k;
    char c;
    
    while(1){
        
        scanf("%c",&c);
        switch(c){
            case 'i':scanf("%d",&k);insert(&root,k);break;
            case 'p':print(root);printf("\n");break;
            case 'q':return 0;
        }
        scanf("\n");
    }

}
