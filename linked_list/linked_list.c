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

void ll_insert_back(struct LinkedList* list, int data) {
   // Create New Node For Insertion
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   if (new_node == NULL) {
       return;
   }
   node_init(new_node, data);

   // Check for Empty List
   if (list->head == NULL) {
	   new_node->next = NULL;
	   list->head = new_node;
	   return;
   }

   // Check For One Item In List
   if (list->head->next == NULL) {
	   list->head->next = new_node;
	   return;
   }

   // Create Pointers to help insert new node
   struct Node* cur = list->head;
   struct Node* prev = NULL;

   // Get Pointer to Last Node
   while (cur != NULL) {
	   prev = cur;
	   cur = cur->next;
   }

   // Insert Node
   prev->next = new_node;
   new_node->next = cur;
}
