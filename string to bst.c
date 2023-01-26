
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;
node *createNode(int k)
{
    node *ne = (node *)malloc(sizeof(node));
    ne->val = k;
    ne->left = ne->right = NULL;
    return ne;
}
node *maketree(char s[], int *start)
{
    if (strlen(s) == 0 || *start >= strlen(s))
        return NULL;
    int num = 0;
    while (*start < strlen(s) && s[*start] != '(' && s[*start] != ')')
    {
        int num_here = (int)(s[*start] - '0');
        num = num * 10 + num_here;
        *start = *start + 1;
    }
    struct Node *root = NULL;
    if (num > 0)
    {
        root = createNode(num);
    }

    if (*start < strlen(s) && s[*start] == '(')
    {
        *start = *start + 1;
        root->left = maketree(s, start);
    }
    if (*start < strlen(s) && s[*start] == ')')
    {
        *start = *start + 1;
        return root;
    }
    if (*start < strlen(s) && s[*start] == '(')
    {
        *start = *start + 1;
        root->right = maketree(s, start);
    }
    if (*start < strlen(s) && s[*start] == ')')
        *start = *start + 1;
    return root;
}
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    char s[1000000] ;
    int start = 0;
    scanf("%[^\n]%*c", s);
    struct Node *root = maketree(s, &start);
    preorder(root);
    return 0;
}