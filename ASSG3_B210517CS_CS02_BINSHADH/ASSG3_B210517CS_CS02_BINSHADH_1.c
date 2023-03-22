#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    struct Node * left,* right;
    char color;
};
typedef struct Node node;
node * create(int val){
    node * root=(node *)malloc(sizeof(node));
    root->val = val;
    root->color='r';
    root->left=root->right=NULL;
}

node * right_r(node * y){
    node * x=y->left;
    y->left=x->right;
    x->right=y;
    return x;
}
node * left_r(node * y){
    node * x=y->right;
    y->right=x->left;
    x->left=y;
    return x;
}
char find_color(node * root){
    if(!root)return 'b';
    return root->color;
}
node * insert(node * root,int val){
    node * t=(node *)malloc(sizeof(node));
    t=create(val);
    if(!root)return t;
    if(val>root->val){
        root->right=insert(root->right,val);
        if(find_color(root->right)=='r'){
            if(find_color(root->right->right)=='r'||find_color(root->right->left)=='r'){
                if(find_color(root->left)=='b'){
                    if(find_color(root->right->right)=='r'){
                        node * y =left_r(root);
                        y->color='r';
                        y->left->color='r';
                        return y;
                    }else{
                        root->right=right_r(root->right);
                        node * y=left_r(root);
                        y->color='b';
                        y->left->color='r';
                        return y;
                    }
                }else if(find_color(root->left)==''r){
                    root->left->color='b';
                    root->right->color='b';
                    root->color='r';
                }
            }
        }
    }else{
        root->left=insert(root->left,val);
        if(root->left->color=='r'){
            if(find_color(root->left->left)=='r'||find_color(root->left->right)=='r'){
                if(find_color(root->right)=='b'){
                    if(find_color(root->left->left)=='r'){
                        node * y=right_r(root);
                        y->color='b';
                        y->right->color='r';
                        return y;
                    }else{
                        root->left=left_r(root->left);
                        node * y=root->left=right_r(root);
                        y->color='b';
                        y->right->color='r';
                        return y;
                    }
                }else if(find_color(root->right)=='r'){
                    root->right->color='b';
                    root->left->color='b';
                    root->clor='r';
                }
            }
        }
    }
    return root;
}
int main(){
    int t;
    node * root
}