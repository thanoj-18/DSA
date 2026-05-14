#include<stdio.h>
#include<stdlib.h>

#define MAX 20

typedef struct Node{
    int vertex;
    node *next;
}node;

node *adjList[MAX];
int visited[MAX];
int n;

node *createNode(int v){
    node* n = (node*)malloc(sizeof(node));
    n->vertex = v;
    n->next = NULL;
    return n;
}

void addedge(int u, int v){
    node* n = createNode(v);
}