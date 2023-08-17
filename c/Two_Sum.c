#include <stdlib.h>

typedef struct {
    long key;
    int value;
} HashMap;

HashMap* createHashMap(int size) {
    HashMap* map = malloc(size * sizeof(HashMap));
    for (int i = 0; i < size; i++) {
        map[i].key = -1;
        map[i].value = -1;
    }
    return map;
}

void insert(HashMap* map, int size, long key, int value) {
    int index = labs(key) % size;
    while (map[index].value != -1) {
        index = (index + 1) % size;
    }
    map[index].key = key;
    map[index].value = value;
}

int find(HashMap* map, int size, long key) {
    int index = labs(key) % size;
    while (map[index].value != -1 && map[index].key != key) {
        index = (index + 1) % size;
    }
    return map[index].value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* res = malloc(2 * sizeof(int));
    HashMap* map = createHashMap(numsSize * 2);

    for (int i = 0; i < numsSize; i++) {
        long complement = target - nums[i];
        int complementIndex = find(map, numsSize * 2, complement);
        if (complementIndex != -1) {
            res[0] = complementIndex;
            res[1] = i;
            break;
        }

        insert(map, numsSize * 2, nums[i], i);
    }

    free(map);
    *returnSize = 2;
    return res;
}
