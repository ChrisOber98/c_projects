#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

// Function to initialze Linked List
void ll_init(struct LinkedList* list);

// Function to initialize Node
void node_init(struct Node* node, int num);

// Functions to insert content
int ll_insert_front(struct LinkedList* list, int data);
int ll_insert_back(struct LinkedList* list, int data);
int ll_insert_at(struct LinkedList* list, int index, int data);

// Functions to remove content
int ll_delete_front(struct LinkedList* list);
int ll_delete_back(struct LinkedList* list);
int ll_delete_at(struct LinkedList* list, int index);
int ll_delete_num(struct LinkedList* list, int data);

#endif
