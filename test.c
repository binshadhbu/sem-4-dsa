#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
    char * word;
    struct node * next;
};
typedef struct node node;
node * make_node(){
    node * ne=(node *)malloc(sizeof(node ));
    ne->word=-1;
    ne->next=NULL;
    return ne;
}
node ** create_hash(int n){
    node ** h=(node **)malloc(sizeof(node *)*n);
    for(int i=0;i<n;i++){
        h[i]=NULL;
    }
    return h;
}