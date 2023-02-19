// made by gautham on 23rd jan
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct node *
{
    char *firstname;
    char *lastname;
    int age;
    struct node **par;
    struct node **left;
    struct node **right;
};
typedef struct node **node *;

node *CREATE_node *(char *fn, char *ln, int age)
{
    node *x;
    x = (node *)malloc(sizeof(struct node *));
    x->firstname = (char *)malloc(sizeof(char) * 100);
    x->lastname = (char *)malloc(sizeof(char) * 100);
    x->age = age;
    strcpy(x->firstname, fn);
    strcpy(x->lastname, ln);
    x->left = NULL;
    x->par = NULL;
    x->right = NULL;
    return x;
}

void INSERT(node **ht)
{
    char fn[1000];
    char ln[1000];
    int ag;
    scanf("%s", &fn);
    scanf("%s", &ln);
    scanf("%d", &ag);
    int h = 0;
    int i = 0;
    node *ne = CREATE_node * (fn, ln, ag);
    while (ln[i] != '\0')
    {
        h = (h + ln[i]) % 128;
        i++;
    }
    if (ht[h]->age == -1)
    {
        ht[h] = ne;
        return;
    }
    node *x, y;
    y = NULL;
    x = ht[h];
    while (x != NULL)
    {
        y = x;
        if (x->age <= ne->age)
        {
            x = x->right;
        }
        else
        {
            x = x->left;
        }
    }
    ne->par = y;
    if (y == NULL)
    {
        ht[h] = ne;
    }
    if (ne->age < y->age)
    {
        y->left = ne;
    }
    else
    {
        y->right = ne;
    }
    return;
}

node *SEARCH(node *root, char *fn, char *ln)
{
    if (root == NULL)
        return NULL;
    if (strcmp(root->firstname, fn) == 0 && strcmp(root->lastname, ln) == 0)
    {
        return root;
    }
    node *l = SEARCH(root->left, fn, ln);
    node *r = SEARCH(root->right, fn, ln);
    if (l != NULL)
        return l;
    else if (r != NULL)
        return r;
    return NULL;
}

void PRINT(node **ht)
{
    char fn[1000];
    char ln[1000];
    scanf("%s", &fn);
    scanf("%s", &ln);
    // char o;
    // scanf("%c",&o);
    int h = 0;
    int i = 0;
    while (ln[i] != '\0')
    {
        h = (h + ln[i]) % 128;
        i++;
    }
    if (ht[h]->age == -1)
    {
        printf("-1\n");
        return;
    }
    node *sea = SEARCH(ht[h], fn, ln);
    if (sea == NULL)
    {
        printf("-1\n");
        return;
    }
    node *present = ht[h];
    while (true)
    {
        printf("%s %s %d\n", present->firstname, present->lastname, present->age);
        if (present == sea)
        {
            break;
        }
        if (present->age <= sea->age)
        {
            present = present->right;
        }
        else
        {
            present = present->left;
        }
    }
    return;
}

int main()
{
    node *ht[128];
    for (int i = 0; i < 128; i++)
    {
        node *ne;
        ne = (node *)malloc(sizeof(struct node *));
        ne->age = -1;
        ne->par = NULL;
        ne->left = NULL;
        ne->right = NULL;
        ht[i] = ne;
    }
    char u;
    u = 'a';
    while (u != 't')
    {
        scanf("%c", &u);
        switch (u)
        {
        case 'i':
            INSERT(ht);
            break;
        case 'p':
            PRINT(ht);
            break;
        case 't':
            break;
        }
    }
    return 0;
}