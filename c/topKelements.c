#include <stdlib.h>

typedef struct node {
    int integer;
    int frequency;
    struct node* next;
} nod;

nod* create_node(int integer) {
    nod* new_node = (nod*)malloc(sizeof(nod));
    new_node->integer = integer;
    new_node->frequency = 1; // Initialize frequency to 1
    new_node->next = NULL;
    return new_node;
}

void insert(nod** ptr, int integer) {
    nod* cur = *ptr;
    nod* prev = NULL;

    while (cur != NULL && cur->integer != integer) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        nod* new_node = create_node(integer);

        if (prev == NULL) {
            *ptr = new_node; // Set as head if list is empty
        } else {
            prev->next = new_node; // Insert at the end
        }
    } else {
        cur->frequency++; // Increment frequency if node already exists
    }
}

int mostfrequent(nod* ptr) {
    nod* cur = ptr;
    int most = 0;
    int mostfrequent = 0;

    while (cur != NULL) {
        if (cur->frequency > most) { // Use > instead of < for comparison
            most = cur->frequency;
            mostfrequent = cur->integer;
        }
        cur = cur->next;
    }

    cur = ptr;
    while (cur != NULL && cur->integer != mostfrequent) {
        cur = cur->next;
    }

    if (cur != NULL) {
        cur->frequency = 0;
    }

    return mostfrequent;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    nod* map = NULL;
    int* array = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        insert(&map, nums[i]);
    }

    for (int i = 0; i < k; i++) {
        array[i] = mostfrequent(map);
    }

    *returnSize = k;
    return array;
}