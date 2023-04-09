
#include <stdio.h>
#include <stdlib.h>
struct node *
{
    int key;
    struct node **parent, *left, *right;
};
typedef struct node **node *;
struct Tree
{
    node *root;
};
typedef struct Tree *tree;
node *CREATE_node *(int k)
{
    node *x;
    x = (node *)malloc(sizeof(struct node *));
    x->key = k;
    x->left = x->parent = x->right = NULL;
    return x;
}
node *SEARCH(tree t, int k)
{
    node *present;
    present = t->root;

    while (present && present->key != k)
    {
        if (present->key != k)
        {
            if (present->key > k)
            {
                present = present->left;
            }
            else
            {
                present = present->right;
            }
        }
    }
    return present;
}

// node * SEARCH(tree t,int k){
//     node * present;
//     present=t->root;

//     if(present->key==k){
//         return present;
//     }
//     if(present){
//         present=(present->key>k)? present->left:present->right;
//         se
//     }
// }

node *MINIMUM(node *a)
{
    if (!a)
        return NULL;
    while (a->left)
    {
        a = a->left;
    }
    return a;
}

node *MAXIMUM(node *a)
{
    if (!a)
        return NULL;
    while (a->right)
    {
        a = a->right;
    }
    return a;
}

void SUCCESSOR(tree t, int k)
{
    node *present;
    present = SEARCH(t, k);
    if (!present)
    {
        printf("%d\n", -1);
        return;
    }
    if (present->right)
    {
        node *cur1 = MINIMUM(present->right);
        printf("%d\n", cur1->key);
        return;
    }
    node *p;
    p = present->parent;
    while (p && present == p->right)
    {
        present = p;
        p = p->parent;
    }
    if (p == NULL)
    {
        printf("%d\n", -1);
    }
    else
    {
        printf("%d\n", p->key);
    }
}

void PREDECESSOR(tree t, int k)
{
    node *present;
    present = SEARCH(t, k);
    if (!present)
    {
        printf("%d\n", -1);
        return;
    }
    if (present->left)
    {
        node *cur1 = MAXIMUM(present->left);
        printf("%d\n", cur1->key);
    }
    else
    {
        node *p;
        p = present->parent;
        if (p)
        {
            while (present == p->left)
            {
                present = p;
                p = p->parent;
            }
        }

        if (!p)
        {
            printf("%d\n", -1);
        }
        else
        {
            printf("%d\n", p->key);
        }
    }
}

void INSERT(tree t, int k)
{
    node *a;
    a = CREATE_node * (k);
    node *x, y;
    y = NULL;
    x = t->root;
    while (x)
    {
        y = x;
        if (x->key <= a->key)
        {
            x = x->right;
        }
        else
        {
            x = x->left;
        }
    }
    a->parent = y;
    if (!y)
    {
        t->root = a;
    }
    else if (a->key < y->key)
    {
        y->left = a;
    }
    else
    {
        y->right = a;
    }
}

void TRANSPLANT(tree t, node *a, node *b)
{
    if (!a->parent)
    {
        t->root = b;
    }
    else if (a == a->parent->left)
    {
        a->parent->left = b;
    }
    else
    {
        a->parent->right = b;
    }
    if (b)
    {
        b->parent = a->parent;
    }
    return;
}

void DELETE(tree t, int k)
{
    node *present = SEARCH(t, k);
    if (!present)
    {
        printf("%d\n", -1);
        return;
    }
    // printf("%d\n", present->key);
    if (!present->left)
    {
        TRANSPLANT(t, present, present->right);
    }
    else if (!present->right)
    {
        TRANSPLANT(t, present, present->left);
    }
    else
    {
        node *cur = MINIMUM(present->right);
        if (cur->parent != present)
        {
            TRANSPLANT(t, cur, cur->right);
            cur->right = present->right;
            cur->right->parent = cur;
        }
        TRANSPLANT(t, present, cur);
        cur->left = present->left;
        cur->left->parent = cur;
    }
}

int LEVEL(tree t, int k)
{
    node *present;
    node *next = present->left;
    int ans = 1;
    present = t->root;
    while (present && present->key != k)
    {
        ans++;
        if (present->key > k)
        {
            present = present->left;
        }
        else
        {
            present = present->right;
        }
    }
    if (present && present->key == k)
    {
        return ans;
    }
    return 0;
}

void intraversal(node *r)
{
    if (r)
    {
        intraversal(r->left);
        printf("%d ", r->key);
        intraversal(r->right);
    }
}
void posttravrsal(node *r)
{
    if (r)
    {
        posttravrsal(r->left);
        posttravrsal(r->right);
        printf("%d ", r->key);
    }
}

void pretraversal(node *r)
{
    if (r)
    {
        printf("%d ", r->key);
        pretraversal(r->left);
        pretraversal(r->right);
    }
}

int main()
{
    tree t;
    t = (tree)malloc(sizeof(struct Tree));
    char c = 'B';
    int k, val;
    node *ptr;
    while (c != 'e')
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'a':
            scanf(" %d", &k);
            INSERT(t, k);
            break;
        case 'd':
            scanf(" %d", &k);
            DELETE(t, k);
            break;
        case 's':
            scanf(" %d", &k);
            ptr = SEARCH(t, k);
            if (!ptr)
            {
                printf("%d\n", -1);
            }
            else
            {
                printf("%d\n", 1);
            }
            break;
        case 'l':
            scanf(" %d", &k);

            if (!LEVEL(t, k))
            {
                printf("%d\n", -1);
            }
            else
            {
                val = LEVEL(t, k);
                printf("%d\n", val);
            }
            break;
        case 'm':
            if (t->root)
            {
                ptr = MINIMUM(t->root);
                printf("%d\n", ptr->key);
            }
            break;
        case 'x':
            if (t->root)
            {
                ptr = MAXIMUM(t->root);
                printf("%d\n", ptr->key);
            }
            break;
        case 'R':
            scanf(" %d", &k);
            PREDECESSOR(t, k);
            break;
        case 'u':
            scanf(" %d", &k);
            SUCCESSOR(t, k);
            break;
        case 'p':
            pretraversal(t->root);
            printf("\n");
            break;
        case 'i':
            intraversal(t->root);
            printf("\n");
            break;
        case 't':
            posttravrsal(t->root);
            printf("\n");
            break;
        case 'e':
            break;
        }
    }
    return 0;
}
