
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000

struct node *
{
    int val;
    struct node **left, *right, *parent;
};
typedef struct node *node *;
node **next = NULL;
node **buildTree(const char *A)
{
    static size_t i = 0;
    i += 2;
    if (A[i] == ')')
    {
        return NULL;
    }
    size_t k = 0;
    char *temp = (char *)malloc(9 * sizeof(char));
    node **p = (node **)malloc(sizeof(node *));
    k = 0;
    while (isdigit(A[i]))
    {
        temp[k++] = A[i++];
    }
    temp[k] = '\0';
    p->val = atoi(temp);
    ++i;
    p->left = buildTree(A);
    if (p->left != NULL)
    {
        next = p->left;
        next->parent = p;
    }
    do
    {
        i += 2;
    } while (A[i] == ')');
    p->right = buildTree(A);
    if (p->right)
    {
        next = p->right;
        next->parent = p;
    }
    return p;
}
node **found = NULL;
void check(node **root, int x)
{
    if (root != NULL)
    {
        if (root->val == x)
        {
            found = root;
            return;
        }
        check(root->left, x);
        check(root->right, x);
    }
}
void print(node **base)
{
    if (base != NULL)
    {

        printf("%d ", base->val);
        print(base->parent);
    }
}
int main()
{
    char *A = (char *)malloc(1000000 * sizeof(char));
    scanf("%[^\n]%*c", A);
    node **root = buildTree(A);
    int x;
    scanf("%d", &x);
    check(root, x);
    if (found == NULL || found->parent == NULL)
    {
        printf("%d", -1);
        return 0;
    }

    print(found->parent);
    return 0;
}
//( 10 ( 5 ( 4 ( 2 ( ) ( ) ) ( ) ) ( 7 ( ) ( ) ) ) ( 12 ( ) ( ) ) )
