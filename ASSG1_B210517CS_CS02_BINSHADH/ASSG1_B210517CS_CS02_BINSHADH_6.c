
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000

struct node {
    int val;
    struct node *left, *right;
}* searched=NULL;
typedef struct node node;

void inorderTraversal(node *root,int x,int y) {
    if (root != NULL) {
        inorderTraversal(root->left,x,y);
        if(root->val>=x&&root->val<=y)
        printf("%d ",root->val);
        inorderTraversal(root->right,x,y);
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
void findsum(node * root,int *sum){
    if(root!=NULL){
        //printf("%d ",root->val);
        *sum=*sum+root->val;
        findsum(root->left,sum);
        findsum(root->right,sum);
    }

}
void solve(node *root,int *check,int *count){
    if(root!=NULL){
        int sum=0;
        findsum(root,&sum);
        if(*check==sum)*count=*count+1;
        solve(root->left,check,count);
        solve(root->right,check,count);
    }
}
int main() { 
    char *A = (char *)malloc(1000000 * sizeof(char));
    scanf("%[^\n]%*c", A);
    node *root = buildTree(A);
    int x,y;
    scanf("%d%d",&x,&y);

     inorderTraversal(root,x,y);
    // int check=0;
    // int count=0;
    // scanf("%d",&check);
    // solve(root,&check,&count);
    // // findsum(root,&count);
    // printf("%d",count);
    printf("\n");
    return 0;
}
