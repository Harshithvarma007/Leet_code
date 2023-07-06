#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // Create prefix and suffix arrays
    int* prefix = (int*)malloc(numsSize * sizeof(int));
    int* suffix = (int*)malloc(numsSize * sizeof(int));

    // Initialize prefix and suffix arrays
    prefix[0] = 1;
    suffix[numsSize - 1] = 1;

    // Calculate prefix array
    for (int i = 1; i < numsSize; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // Calculate suffix array
    for (int i = numsSize - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Calculate answer array
    int* answer = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        answer[i] = prefix[i] * suffix[i];
    }

    // Set the return size
    *returnSize = numsSize;

    // Free memory
    free(prefix);
    free(suffix);

    return answer;
}