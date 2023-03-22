
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
struct Node
{
    int key;
    struct Node *left, *right;
    int number;
};
typedef struct Node *node;

struct Tree
{
    node root;
};
typedef struct Tree *tree;

int number_of_child(node root)
{
    int lh = -1, rh = -1;
    if (root->left)
        lh = root->left->number;
    if (root->right)
        lh = root->right->number;
    return lh > rh ? lh + 1 : rh + 1;
}

int balance_factor(node root)
{
    if (root == NULL)
        return -1;
    int lh = -1, rh = -1;
    if (root->left)
        lh = root->left->number;
    if (root->right)
        lh = root->right->number;
    return lh - rh;
}

void RL(node *root)
{
    node ne = (*root)->right;
    (*root)->right = ne->left;
    ne->left = *root;
    (*root)->number = number_of_child(*root);
    ne->number = number_of_child(ne);
    *root = ne;
}

void RR(node *root)
{
    node ne = (*root)->left;
    (*root)->left = ne->right;
    ne->right = *root;
    (*root)->number = number_of_child(*root);
    ne->number = number_of_child(ne);
    *root = ne;
}

void insert(node *root, node ele)
{
    if (*root == NULL)
    {
        *root = ele;
        return;
    }
    if ((*root)->key == ele->key)
    {
        return;
    }
    if ((*root)->key > ele->key)
    {
        insert(&((*root)->left), ele);
        if (balance_factor(*root) == 2)
        {
            if (balance_factor((*root)->left) == 1)
            {
                RR(root);
            }
            else
            {
                RL(&((*root)->left));
                RR(root);
            }
        }
    }
    else
    {
        insert(&((*root)->right), ele);
        if (balance_factor(*root) == -2)
        {
            if (balance_factor((*root)->right) == -1)
            {
                RL(root);
            }
            else
            {
                RR(&((*root)->right));
                RL(root);
            }
        }
    }
    (*root)->number = number_of_child(*root);
    return;
}

node MAXIMUM(node root)
{
    node req = root;
    if (root == NULL)
        return NULL;
    while (req->right != NULL)
    {
        req = req->right;
    }
    return req;
}

void INORDER(node n, int a[], int *count)
{
    if (n == NULL)
    {
        return;
    }

    // printf("%d ", n->key);
    INORDER(n->left, a, count);
    a[*count] = n->key;
    *count = *count + 1;
    INORDER(n->right, a, count);

    return;
}

void PRINTTREE(tree t)
{
    int count = 0;
    int a[1000];
    INORDER(t->root, a, &count);
    if(count%2==0)
    printf("%d",a[count/2-1]);
    else
    printf("%d",a[count/2]);
    

   
    return;
}

int main()
{
    tree t;
    t = (tree)malloc(sizeof(struct Tree));
    int k;
    char c = 'a';
    while (EOF != (c = fgetc(stdin)))
    {
        switch (c)
        {
        case 'i':
        {
            scanf("%d", &k);
            node ne = (node)malloc(sizeof(struct Node));
            ne->key = k;
            ne->right = ne->left = NULL;
            ne->number = 0;

            insert(&(t->root), ne);
            break;
        }
        case 'g':
        {
            PRINTTREE(t);
            break;
        }
        case 't':
            break;
        default:
            continue;
        }
    }
    return 0;
}