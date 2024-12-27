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


int main(int argc, char ** argv) {
    test_ll_insert_front();
}


