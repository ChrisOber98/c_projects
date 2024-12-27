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
void ll_insert_front(struct LinkedList* list, int data);
void ll_insert_back(struct LinkedList* list, int data);

#endif
