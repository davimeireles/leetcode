/* Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation. */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    int* ret = calloc(numsSize, sizeof(int));
    if (!ret)
        return NULL;

    int* prefix = calloc(numsSize, sizeof(int));
    int* suffix = calloc(numsSize, sizeof(int));
    if (!prefix || !suffix) {
        free(ret);
        return NULL;
    }

    prefix[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    suffix[numsSize - 1] = 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < numsSize; i++) {
        ret[i] = prefix[i] * suffix[i];
    }

    free(prefix);
    free(suffix);

    *returnSize = numsSize;
    return ret;
}