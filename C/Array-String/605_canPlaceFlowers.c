/*
You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's
where 0 means empty and 1 means not empty, and an integer n,
return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
*/

#include <stdbool.h>
#include <stdio.h>

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
    if (flowerbedSize == 1 && n > 0) {
        if (flowerbed[0] == 0) {
            flowerbed[0] = 1;
            n--;
        }
        if (n > 0)
            return false;
        return true;
    }

    for (int i = 0; i < flowerbedSize && n > 0; i++) {
        if (i == 0) {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        else if (i == flowerbedSize - 1) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        else if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
            flowerbed[i] = 1;
            n--;
        }
    }

    if (n > 0)
        return false;
    return true;
}

int main()
{
    int arr[] = {0,0};
    int size = 2;
    int n = 5;

    canPlaceFlowers(arr, size, n);

    /*     for (int i = 0; i < flowerbedSize; i++)
        printf("[%d] ", flowerbed[i]);
 */
}
