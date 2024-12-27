#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

// Function to initialze Linked List
void ll_init(struct LinkedList* list){
    list->head = NULL;
}

void node_init(struct Node* node, int num) {
    node->data = num;
    node->next = NULL;
}

void ll_insert_front(struct LinkedList* list, int data) {
   // Create New Node For Insertion
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   if (new_node == NULL) {
       return;
   }
   node_init(new_node, data);

   // Insert at front
   new_node->next = list->head;
   list->head = new_node;
}
