int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* res = (int*)malloc(2 * sizeof(int));
    int i = 0;
    int j = numbersSize - 1;
    
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target) {
            res[0] = i + 1;
            res[1] = j + 1;
            break;
        } else if (sum > target) {
            j--;
        } else {
            i++;
        }
    }
    
    *returnSize = 2;
    return res;
}