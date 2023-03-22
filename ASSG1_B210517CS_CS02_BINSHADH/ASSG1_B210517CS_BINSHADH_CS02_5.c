#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node *
{
    int val;
    node **next, *left, *parent;
};
typedef struct node **node *;
struct max
{
    int sum;
    node **leaf;
} node **make(char *a)
{
    int key, temp, i;
    a += 2;
    int k[1000];
    if (*a == ')')
        return NULL;
    key = 0;
    i = 0;
    while ((*a <= '9' && *a >= '0') || *a == '0')
    {
        k[i++] = *a++;
    }
    k[i] = '\0';
    key = atoi(k);
    node **root = (node **)malloc(sizeof(node *));
    root->val = key;
    a++;
    root->left = make(a);
    a++;
}
int main()
{
    char *a = (char *)malloc(sizeof(1000 * char));
    scanf("%[^\n]s", a);
    node **root = make(a);
}
