/*
There are n kids with candies.

You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has
and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if
after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.
*/

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int     bool_index = 0;
    bool    greatest = false;

    bool *ret = calloc(candiesSize, sizeof(bool));
    if (!ret)
        return NULL;
    
    for (int i = 0; i < candiesSize; i++)
    {
        for (int j = 0; j < candiesSize; j++)
        {
            int current = candies[i] + extraCandies;
            if (current >= candies[j])
                greatest = true;
            else
            {
                greatest = false;
                break;
            }    
        }
        ret[bool_index] = greatest;
        bool_index++;
    }
    *returnSize = candiesSize;
    return ret;
}
