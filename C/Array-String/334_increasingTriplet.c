/*	
Given an integer array nums, return true if there exists 
a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].
If no such indices exists, return false.
*/

# include <stdbool.h>
# include <stdio.h>
# include <limits.h>

 bool increasingTriplet(int* nums, int numsSize) {
    
	if (numsSize < 3)
		return false;

	int first = INT_MAX, second = INT_MAX;

	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] <= first)
			first = nums[i];
		else if (nums[i] <= second)
			second = nums[i];
		else
			return true;
	}
	return false;
}