/*
You are given two strings word1 and word2.
Merge the strings by adding letters in alternating order, starting with word1.
If a string is longer than the other, append the additional letters onto the end of the merged string.
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char * mergeAlternately(char * word1, char * word2)
{
    int lenWord1 = strlen(word1);
    int lenWord2 = strlen(word2);
    int i = 0;

    char *mergedString = calloc((lenWord1 + lenWord2 + 1), sizeof(char));

    while (*word1 || *word2)
    {
        if (*word1)
        {
            mergedString[i++] = *word1;
            word1++;
        }
        if (*word2)
        {
            mergedString[i++] = *word2;
            word2++;
        }
    }

    return mergedString;
}