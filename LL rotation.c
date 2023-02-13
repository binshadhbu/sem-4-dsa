#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
struct Node {
    int val;
    node *left,*right,*parent;
    int height;
};
typedef struct Node node;
int Node_height(node * root){
    if(!root)return NULL;
    int hl=root&&root->left?root->left->height:0;
    int hr=root&&root->right?root->right->height:0;
    return hl>hr?hl+1:hr+1;
}
node * insert(node * root,int key){
    node *
    if(root==NULL){

    }
}

int main(){

}