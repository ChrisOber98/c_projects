#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

// Function to test insert front
void test_ll_insert_front() {

    printf("----TESTING INSERT FRONT----\n");

    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    ll_init(list);

    // TEST INIT WORKED
    assert(list->head == NULL);

    ll_insert_front(list, 12);

    // TEST Insert into Empty List
    assert(list->head->data == 12);
    assert(list->head->next == NULL);

    ll_insert_front(list, 24);

    assert(list->head->data == 24);
    assert(list->head->next->data == 12);
    assert(list->head->next->next == NULL);

    ll_destruct(list);

    printf("ALL TESTS PASSED\n\n");
}

// Functin to test insert back
void test_ll_insert_back() {
    printf("----TESTING INSERT BACK----\n");

    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    ll_init(list);

    ll_insert_back(list, 12);

    // Test Insert into Empty List
    assert(list->head->data == 12);
    assert(list->head->next == NULL);

    // Test insert into one item list
    ll_insert_back(list, 24);
    assert(list->head->data == 12);
    assert(list->head->next->data == 24);
    assert(list->head->next->next == NULL);

    // Test insert into more then one item list
    ll_insert_back(list, 48);
    assert(list->head->data == 12);
    assert(list->head->next->data == 24);
    assert(list->head->next->next->data == 48);
    assert(list->head->next->next->next == NULL);

    ll_destruct(list);

    printf("ALL TESTS PASSED\n\n");
}

// Functin to test insert back
void test_ll_insert_at() {
    printf("----TESTING INSERT AT----\n");

    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    ll_init(list);

    // TEST INSERT AT EMPTY LIST
    assert(ll_insert_at(list, 1, 12) != 1);
    assert(ll_insert_at(list, -1, 12) != 1);
    assert(ll_insert_at(list, 0, 12) == 1);
    assert(list->head->data == 12);
    assert(list->head->next == NULL);

    // Test INSERTING INTO 1 Item List
    assert(ll_insert_at(list, -1, 24) != 1);
    assert(ll_insert_at(list, 5, 24) != 1);
    assert(ll_insert_at(list, 1, 24) == 1);
    assert(list->head->data == 12);
    assert(list->head->next->data == 24);
    assert(list->head->next->next == NULL);

    // Test INSERTING INTO 2+ Item list at middle and end
    assert(ll_insert_at(list, -1, 48) != 1);
    assert(ll_insert_at(list, 5, 48) != 1);
    assert(ll_insert_at(list, 2, 48) == 1);
    assert(list->head->data == 12);
    assert(list->head->next->data == 24);
    assert(list->head->next->next->data == 48);
    assert(list->head->next->next->next == NULL);

    assert(ll_insert_at(list, -1, 96) != 1);
    assert(ll_insert_at(list, 10, 96) != 1);
    assert(ll_insert_at(list, 2, 96) == 1);
    assert(list->head->data == 12);
    assert(list->head->next->data == 24);
    assert(list->head->next->next->data == 96);
    assert(list->head->next->next->next->data == 48);
    assert(list->head->next->next->next->next == NULL);

    ll_destruct(list);

    printf("ALL TESTS PASSED\n\n");

}

// Function to test delete font
void test_ll_delete_front() {
    printf("----TESTING DELETE FRONT----\n");

    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    ll_init(list);

    // Test deletion from empty list
    assert(ll_delete_front(list) != 1);

    // add 3 values for deletion
    ll_insert_front(list, 12);
    ll_insert_front(list, 22);
    ll_insert_front(list, 32);
    

    // Test deletion from non empty list
    assert(list->head->data == 32);
    assert(list->head->next->data == 22);
    assert(list->head->next->next->data == 12);
    assert(ll_delete_front(list) == 1);
    assert(list->head->data == 22);
    assert(list->head->next->data == 12);
    assert(ll_delete_front(list) == 1);
    assert(list->head->data == 12);
    assert(ll_delete_front(list) == 1);
    assert(list->head == NULL);
    assert(ll_delete_front(list) != 1);

    ll_destruct(list);

    printf("ALL TESTS PASSED\n\n");
}

// Function to test delete font
void test_ll_delete_back() {
    printf("----TESTING DELETE BACK----\n");

    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    ll_init(list);

    // Test deletion from empty list
    assert(ll_delete_back(list) != 1);

    // add 3 values for deletion
    ll_insert_front(list, 12);
    ll_insert_front(list, 22);
    ll_insert_front(list, 32);
    

    // Test deletion from non empty list
    assert(list->head->data == 32);
    assert(list->head->next->data == 22);
    assert(list->head->next->next->data == 12);
    assert(ll_delete_back(list) == 1);
    assert(list->head->data == 32);
    assert(list->head->next->data == 22);
    assert(ll_delete_back(list) == 1);
    assert(list->head->data == 32);
    assert(ll_delete_back(list) == 1);
    assert(list->head == NULL);
    assert(ll_delete_back(list) != 1);

    ll_destruct(list);

    printf("ALL TESTS PASSED\n\n");
}

void test_ll_delete_at() {
    printf("----TESTING DELETE AT----\n");

    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    ll_init(list);

    // Test deletion from empty list
    assert(ll_delete_at(list, 0) != 1);
    assert(ll_delete_at(list, 10) != 1);

    // add 1 values for deletion
    ll_insert_front(list, 12);
    
    // TEST deletion from 1 item list
    assert(ll_delete_at(list, 1) != 1);
    assert(ll_delete_at(list, -1) != 1);
    assert(ll_delete_at(list, 0) == 1);
    assert(list->head == NULL);
 
    // add 3 values for deletion
    ll_insert_front(list, 12);
    ll_insert_front(list, 22);
    ll_insert_front(list, 32);

    //Delete from middle
    assert(ll_delete_at(list, 1) == 1);
    assert(list->head->data == 32);
    assert(list->head->next->data == 12);

    // ADD IT BACK
    ll_insert_front(list, 42);

    //Delete from end
    assert(ll_delete_at(list, 2) == 1);
    assert(list->head->data == 42);
    assert(list->head->next->data == 32);

    // ADD IT BACK
    ll_insert_front(list, 52);

    //Delete from start
    assert(ll_delete_at(list, 0) == 1);
    assert(list->head->data == 42);
    assert(list->head->next->data == 32);

    //Delete to empty
    assert(ll_delete_at(list, 1) == 1);
    assert(list->head->data == 42);
    assert(ll_delete_at(list, 0) == 1);
    assert(list->head == NULL);
    assert(ll_delete_at(list, 0) != 1);

    ll_destruct(list);

    printf("ALL TESTS PASSED\n\n");
}
int main(int argc, char ** argv) {
    test_ll_insert_front();
    test_ll_insert_back();
    test_ll_insert_at();
    test_ll_delete_front();   
    test_ll_delete_back();
    test_ll_delete_at();
}


