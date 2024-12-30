#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

// Function to initialze Linked List
void ll_init(struct LinkedList* list){
    list->head = NULL;
}

int ll_destruct(struct LinkedList* list) {
    struct Node* temp = NULL;

    while(list->head != NULL) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }   

    free(list->head);
    free(list);

    return 1; 
}

void node_init(struct Node* node, int num) {
    node->data = num;
    node->next = NULL;
}

int ll_insert_front(struct LinkedList* list, int data) {
   // Create New Node For Insertion
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   if (new_node == NULL) {
       fprintf(stderr, "FAILED TO ALLOCATE NEW_NODE.\n");		   
       return -1;
   }
   node_init(new_node, data);

   // Insert at front
   new_node->next = list->head;
   list->head = new_node;
   
   return 1;
}

int ll_insert_back(struct LinkedList* list, int data) {
   // Create New Node For Insertion
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   if (new_node == NULL) {
	fprintf(stderr, "FAILED TO ALLOCATE NEW_NODE.\n");  
	return -1;
   }
   node_init(new_node, data);

   // Check for Empty List
   if (list->head == NULL) {
	   new_node->next = NULL;
	   list->head = new_node;
	   return 1;
   }

   // Check For One Item In List
   if (list->head->next == NULL) {
	   list->head->next = new_node;
	   return 1;
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

   return 1;
}

int ll_insert_at(struct LinkedList* list, int at, int data) {
   // Create New Node For Insertion
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "FAILED TO ALLOCATE NEW_NODE.\n");
        free(new_node);
        return -1;
   }
   node_init(new_node, data);

   // Check for out of bounds
   if (list->head == NULL && at != 0) {
        fprintf(stderr, "OUT OF BOUNDS ERROR.\n");
        free(new_node);
        return -2;
   }

   // Check for insertion at 0
   if (at == 0) {
        new_node->next = NULL;
        list->head = new_node;
        return 1;
   }

   // Create Pointers to help insert new node
   struct Node* cur = list->head;
   struct Node* prev = NULL;
   int counter = 0;

   // Get Pointer to Last Node
   while (cur != NULL && counter != at) {
        prev = cur;
        cur = cur->next;
        counter++;
   }

   // Insert Node
   if (counter == at) {
        prev->next = new_node;
        new_node->next = cur;
        return 1;
   }
   else {
        fprintf(stderr, "OUT OF BOUNDS ERROR.\n");
        free(new_node);
        return -2;
   }
}

int ll_delete_front(struct LinkedList* list) {
	// Check for Empty List
	if (list->head == NULL) {
		fprintf(stderr, "TRIED TO DELETE FROM EMPTY LIST.\n");
		return -3;
	}

	// Delete from front of list
	struct Node* temp = list->head;
	list->head = list->head->next;
	free(temp);

	return 1;
}

