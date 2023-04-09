#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Node
{
    int val;
    struct Node *left, *right;
    char color;
};
typedef struct Node node;
node *create(int val)
{
    node *root = (node *)malloc(sizeof(node));
    root->val = val;
    root->color = 'R';
    root->left = root->right = NULL;
}

node *right_r(node *y)
{
    node *x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}
node *left_r(node *y)
{
    node *x = y->right;
    y->right = x->left;
    x->left = y;
    return x;
}
char find_color(node *root)
{
    if (!root)
        return 'B';
    return root->color;
}
node *insert(node *root, int val)
{
    node *t = (node *)malloc(sizeof(node));
    t->color = 'B';
    t = create(val);
    if (!root)
        return t;
    if (val > root->val)
    {
        root->right = insert(root->right, val);
        if (find_color(root->right) == 'R')
        {
            if (find_color(root->right->right) == 'R' || find_color(root->right->left) == 'R')
            {
                if (find_color(root->left) == 'B')
                {
                    if (find_color(root->right->right) == 'R')
                    {
                        node *y = left_r(root);
                        y->color = 'B';
                        y->left->color = 'R';
                        return y;
                    }
                    else
                    {
                        root->right = right_r(root->right);
                        node *y = left_r(root);
                        y->color = 'B';
                        y->left->color = 'R';
                        return y;
                    }
                }
                else if (find_color(root->left) == 'R')
                {
                    root->left->color = 'B';
                    root->right->color = 'B';
                    root->color = 'R';
                }
            }
        }
    }
    else
    {
        root->left = insert(root->left, val);
        if (root->left->color == 'R')
        {
            if (find_color(root->left->left) == 'R' || find_color(root->left->right) == 'R')
            {
                if (find_color(root->right) == 'B')
                {
                    if (find_color(root->left->left) == 'R')
                    {
                        node *y = right_r(root);
                        y->color = 'B';
                        y->right->color = 'R';
                        return y;
                    }
                    else
                    {
                        root->left = left_r(root->left);
                        node *y = right_r(root);
                        y->color = 'B';
                        y->right->color = 'R';
                        return y;
                    }
                }
                else if (find_color(root->right) == 'R')
                {
                    root->right->color = 'B';
                    root->left->color = 'B';
                    root->color = 'R';
                }
            }
        }
    }
    return root;
}
void print(node *root)
{
    printf("( ");
    if (root != NULL)
    {

        printf("%d %c ", root->val, root->color);
        print(root->left);
        print(root->right);
    }
    printf(") ");
}
int main()
{
    int t = 0;
    node *root = (node *)malloc(sizeof(node));
    root = NULL;

    while (1)
    {
        t = 0;
        char *s = (char *)malloc(20 * sizeof(char));
        scanf("%s", s);
        if (s[0] == 't')
            return 0;
        t = atoi(s);
        root = insert(root, t);
        root->color = 'B';
        print(root);
        printf("\n");
    }
}