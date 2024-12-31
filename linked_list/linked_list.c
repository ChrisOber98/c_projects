#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

// Function to initialze Linked List
void ll_init(struct LinkedList* list){
    list->head = NULL;
}

// Function to deconstruct Linked List
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

// Function to initialize a node struct
void node_init(struct Node* node, int num) {
    node->data = num;
    node->next = NULL;
}

// Function to insert at the front of a linked list
// return 1: SUCCESS
// return -1: ALLOCATION ERROR
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

// Function to insert at end of linked list
// return 1: SUCESS
// return -1: ALLOCATION ERROR
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

// Function to insert at a specific index in linked list
// return 1: SUCESS
// return -1: ALLOCATION ERROR
// return -2: OUT OF BOUNDS ERROR
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

// Function to delete from front of linked list
// return 1: SUCCESS
// return -3: DELETION FROM EMPTY LIST
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

// Functon to delete at end of linked list
int ll_delete_back(struct LinkedList* list) {
	// Check for Empty List
	if (list->head == NULL) {
		fprintf(stderr, "TRIED TO DELETE FROM EMPTY LIST.\n");
		return -3;
	}

    // Check if One element in Lust
    if (list->head->next == NULL) {
        struct Node* temp = list->head;
        list->head = NULL;
        free(temp);
        return 1;
    }

	// Delete from back of list
	struct Node* cur = list->head;
    struct Node* prev = NULL;

    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    } 

    prev->next = cur->next;
    free(cur);

	return 1;
}

// Function to delete at a specific index in linked list
// return 1: SUCCESS
// return -2: OUT OF BOUNDS ERROR
int ll_delete_at(struct LinkedList* list, int index) {
   // Check for out of bounds
   if (list->head == NULL) {
        fprintf(stderr, "OUT OF BOUNDS ERROR.\n");
        return -2;
   }

   // Check for deletion at 0
   if (index == 0) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return 1;
   }

   // Create Pointers to help insert new node
   struct Node* cur = list->head;
   struct Node* prev = NULL;
   int counter = 0;

   // Get Pointer to Last Node
   while (cur->next != NULL && counter != index) {
       prev = cur;
       cur = cur->next;
       counter++;
   }

   // Delete Node
   if (counter == index) {
        prev->next = cur->next;
        free(cur);
        return 1;
   }
   else {
        fprintf(stderr, "OUT OF BOUNDS ERROR.\n");
        return -2;
   }
}

// Function to delete the first instance of a number in a linked list
// return non negative:
// return -4: did not find value
int ll_delete_num(struct LinkedList* list, int data) {
    // Check for empty List
    if (list->head == NULL) {
        return -4;
    }

    // Check for 1 element list removal
    if (list->head->data == data) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return 1;
    }

    // Create Nodes for deletion
    struct Node* cur = list->head;
    struct Node* prev = NULL;

    while (cur->next != NULL && cur->data != data) {
        prev = cur;
        cur = cur->next;
    }

    // Check if found value and delete if so
    if (cur->data == data) {
        prev->next = cur->next;
        free(cur);
        return 1;    
    } else {
        return -4;
    }
}

void ll_display(struct LinkedList* list) {
    struct Node* cur = list->head;
    
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }

    printf("NULL\n");

    return;
}
