#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
struct node *
{
    char *name;
    char *roll;
    int age;
    struct node **next;
};
typedef struct node *node *;
struct stack
{
    node **root[4];
    node **head[4];
};
typedef struct stack st;
node **create_node *(char *name, char *roll, int age)
{
    node **t = (node **)malloc(sizeof(node *));
    t->name = (char *)malloc(sizeof(char) * 100);
    t->roll = (char *)malloc(sizeof(char) * 100);
    t->age = age;
    strcpy(t->name, name);
    strcpy(t->roll, roll);
    t->next = NULL;
    return t;
}
void student_list(node **head)
{
    node **count = head;
    int c = 0;
    while (count->next)
    {
        c++;
        count = count->next;
    }
    count = head;
    printf("%d ", c);
    while (count->next)
    {
        printf("%s", count->name);
    }
    printf("\n");
}
void branch(char br[], st *table)
{
    for (int i = 0; i < 4; i++)
    {
        i while (table->head[])
    }
}
void insert(st *table)
{
    char *name, *roll;
    int age;
    name = (char *)malloc(sizeof(char) * 100);
    age = (char *)malloc(sizeof(char) * 100);
    scnaf("%s", name);
    scanf("%d", roll);
    scanf("%d", age);
    node **t = create_node * (name, roll, age);
    int index = 0, i = 0;
    while (name[i] != "\0")
    {
        index = index + name[i];
    }
    index = index + age;
    index = index % 4;
    if (table->head[index] = NULL)
    {
        table->head[index] = t;
        table->root[index] = t;
    }
    else
    {
        t->next = table->head[indx];
        table->head[index] = t;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    st *table;
    for (int i = 0; i < 4; i++)
    {
        node **ne = (node **)malloc(sizeof(node *));
        ne->name = ne->roll = NULL;
        ne->age = -1;
        ne->next = NULL;
        table->root[i] = ne;
        table->head[i] = ne;
        table->root[i] = ne;
        table->head[i] = ne;
    }
}