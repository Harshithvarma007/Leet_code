#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define HASH_SIZE 10000

typedef struct node {
    int val;
    struct node* next;
} NODE;

NODE* create_node(int val)
{
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void insert_node(NODE** hash, int val)
{
    int index = abs(val) % HASH_SIZE;
    NODE* new_node = create_node(val);
    new_node->next = hash[index];
    hash[index] = new_node;
}

bool check_val(NODE** hash, int val)
{
    int index = abs(val) % HASH_SIZE;
    NODE* current = hash[index];
    while (current != NULL) {
        if (current->val == val)
            return true;
        current = current->next;
    }
    insert_node(hash, val);
    return false;
}

bool containsDuplicate(int* nums, int numsSize)
{
    NODE** hash = (NODE**)malloc(HASH_SIZE * sizeof(NODE*));
    for (int i = 0; i < HASH_SIZE; i++)
        hash[i] = NULL;

    for (int i = 0; i < numsSize; i++) {
        if (check_val(hash, nums[i]))
            return true;
    }

    // Clean up hash set
    for (int i = 0; i < HASH_SIZE; i++) {
        NODE* current = hash[i];
        while (current != NULL) {
            NODE* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hash);

    return false;
}


