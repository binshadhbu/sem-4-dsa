#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node *
{
    int val;
    struct node **left, *right, *parent;
};
typedef struct node *node *;

node **make(char *str)
{
    int temp, i;
    str += 2;
    if (*str == ')')
        return NULL;
    i = 0;
    char k[1000];
    while ((*str >= '0' && *str <= '9') || *str == -'-')
    {
        k[i++] = *str;
        str++;
    }
    k[i] = '\0';
    int key = atoi(k);
    node **root = (node **)malloc(sizeof(node *));
    root->val = key;
    str++;
    root->left = make(str);
    str++;
    temp = 1;
    while (temp != 0)
    {
        if (*str == '(')
            temp++;
        if (*str == ')')
            temp--;
        str++;
    }
    str++;
    node **right = make(str);
    root->right = right;
    return root;
}

void print(node **root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->val);
    print(root->left);
    print(root->right);
}
int main()
{
    node **root = NULL;
    char *str = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]s", str);
    root = make(str);
    print(root);
    return 0;
}