#ifndef SLL_H
#define SLL_H

struct Node{
    int item;
    struct Node *next;    
};

struct SLL{
    struct Node *start;
};

void CreateList(struct SLL* list);
int isEmpty(struct SLL* list);

void insert_at_start(struct SLL* list , int data);
void insert_at_end(struct SLL* list , int data);

struct Node* Search(struct SLL* list , int data);
void insert_after(struct Node *temp , int data);

void delete_first(struct SLL* list);
void delete_last(struct SLL* list);
void delete_item(struct SLL* list , int data);

void show(struct SLL* list);




#endif