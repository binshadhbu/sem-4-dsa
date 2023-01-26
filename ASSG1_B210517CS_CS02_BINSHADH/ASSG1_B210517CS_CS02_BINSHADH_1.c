
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct node {
    int val;
    struct node *left, *right;
}* searched=NULL;
typedef struct node node;

void printTree(node *root,int x) {
    if (root != NULL) {
        if(root->val==x){
            searched=root;
        }
        printTree(root->left,x);
        printTree(root->right,x);
    }
}
node *buildTree(const char *A) { 
    static size_t i = 0;
    i += 2;
    if (A[i] == ')') {
        return NULL;
    }
    size_t k = 0;
    char *temp = (char *)malloc(9 * sizeof(char));
    node *p = (node *)malloc(sizeof(node));
    k = 0;
    while (isdigit(A[i])) {
        temp[k++] = A[i++];
    }
    temp[k] = '\0';
    p->val = atoi(temp);
    ++i;
    p->left = buildTree(A);
    do {
        i += 2;
    } while (A[i] == ')');
    p->right = buildTree(A);
    return p;
}

void preorderTraversal(node *root,int k) {
    if (root != NULL) {
        if(k==0)
        printf("%d ",root->val);
        preorderTraversal(root->left,k-1);
        preorderTraversal(root->right,k-1);
    }
}

int main() { 
    char *A = (char *)malloc(1000000* sizeof(char));
    scanf("%[^\n]%*c", A);
    node *root = buildTree(A);
   
    int x,k;
    scanf("%d",&x);
    scanf("%d",&k);
    node * se;
     printTree(root,x);
    se=searched;
    if(!se){
        if(se->left==NULL&se->right==NULL){
            printf("%d",-1);
        return 0;
        }
        
    }
    preorderTraversal(se,k);
    
   // void printde(se,int x,int k);
    
    printf("\n");
    return 0;
}
