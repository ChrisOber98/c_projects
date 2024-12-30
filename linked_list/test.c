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

    printf("ALL TESTS PASSED\n\n");

}

int main(int argc, char ** argv) {
    test_ll_insert_front();
    test_ll_insert_back();
    test_ll_insert_at();
}


