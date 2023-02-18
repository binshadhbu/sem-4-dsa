
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct Node
{
    int key;
    struct Node *left, *right;
    int height;
};
typedef struct Node *node;

struct Tree
{
    node root;
};
typedef struct Tree *tree;


int height(node root)
{
    int lh=-1, rh=-1;
    if(root->left)lh=root->left->height;
    if(root->right)lh=root->right->height;
    return lh > rh ? lh + 1 : rh + 1;
}

int balance_factor(node root)
{
    if (root == NULL)
        return -1;
    int lh=-1, rh=-1;
    if(root->left)lh=root->left->height;
    if(root->right)lh=root->right->height;
    return lh - rh;
}

void RL(node *root)
{
    node ne = (*root)->right;
    (*root)->right = ne->left;
    ne->left = *root;
    (*root)->height = height(*root);
    ne->height = height(ne);
    *root = ne;
}

void RR(node *root)
{
    node ne = (*root)->left;
    (*root)->left = ne->right;
    ne->right = *root;
    (*root)->height = height(*root);
    ne->height = height(ne);
    *root = ne;
}

node SEARCH(tree t, int k)
{
    node root=NULL;
    root = t->root;
    if(!root)return root;
    while (root->key != k)
    {
        if (root->key > k)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
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
    (*root)->height = height(*root);
    return;
}

node MAXIMUM(node root)
{
    node req = root;
    if(root==NULL)return NULL;
    while (req->right != NULL)
    {
        req = req->right;
    }
    return req;
}

node delete(node ele, int k)
{
    if (ele == NULL)
        return ele;
    if (ele->key < k)
        ele->right = delete(ele->right, k);
    else if (ele->key > k)
        ele->left = delete(ele->left, k);
    else
    {
        if (ele->left == NULL || ele->right == NULL)
        {
            node cur;
            cur=ele->left?cur=ele->left:ele->right;
            
            if (!cur)
            {
                cur = ele;
                ele = NULL;
            }
            else
            {
                *ele = *cur;
            }
        }
        else
        {
            node pre = MAXIMUM(ele->left);
            ele->key = pre->key;
            ele->left = delete(ele->left, ele->key);
        }
    }
    if (ele == NULL)
        return ele;
    ele->height = height(ele);
    if (balance_factor(ele) > 1 && balance_factor(ele->left) >= 0)
    {
        RR(&ele);
    }
    if (balance_factor(ele) > 1 && balance_factor(ele->left) < 0)
    {
        RL(&(ele->left));
        RR(&ele);
        return ele;
    }
    if (balance_factor(ele) < -1 && balance_factor(ele->right) <= 0)
    {
        RL(&ele);
        return ele;
    }
    if (balance_factor(ele) < -1 && balance_factor(ele->right) > 0)
    {
        RR(&(ele->right));
        RL(&ele);
        return ele;
    }
    return ele;
}

void INORDER(node n)
{
    if (n == NULL)
    {
        printf("( ) ");
        return;
    };
    printf("%c ", '(');
    printf("%d ", n->key);
    INORDER(n->left);
    INORDER(n->right);
    printf("%c ", ')');
    return;
}

void PRINTTREE(tree t)
{
    INORDER(t->root);
    printf("\n");
    return;
}

int main()
{
    tree t;
    t = (tree)malloc(sizeof(struct Tree));
    int k;
    char c = 'a';
    while (c != 'e')
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
        {
            scanf(" %d", &k);
            node ne=(node )malloc(sizeof(struct Node));
            ne->key=k;
            ne->right=ne->left=NULL;
            ne->height=0;
           
            insert(&(t->root), ne);
            break;
        }
        case 's':
        {
            scanf(" %d", &k);
            node pre = SEARCH(t, k);
            if (pre == NULL)
            {
                printf("FALSE\n");
            }
            else
            {
                printf("TRUE\n");
            }
            break;
        }
        case 'd':
        {
            scanf(" %d", &k);
            node pre = SEARCH(t, k);
            if (pre != NULL)
            {
                t->root = delete(t->root, k);
                printf("%d\n", k);
            }
            else
            {
                printf("FALSE\n");
            }
            break;
        }

        case 'b':
        {
            scanf(" %d", &k);
            node ele = SEARCH(t, k);
            if (ele == NULL)
            {
                printf("FALSE\n");
            }
            else
            {
                printf("%d\n", balance_factor(ele));
            }
            break;
        }
        case 'p':
        {
            PRINTTREE(t);
            break;
        }
        case 'e':
            break;
        }
    }
    return 0;
}