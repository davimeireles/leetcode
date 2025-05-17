/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

static bool is_vowel(int c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    return false;
}

char *reverseVowels(char *s)
{
    int i = 0;
    int j = strlen(s) - 1;
    char temp;

    while (i < j)
    {
        while (i < j && !is_vowel(s[i]))
            ++i;
        
        while (i < j && !is_vowel(s[j]))
            --j;

        if (i < j)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ++i;
            --j;
        }
    }
    return (s);
}

int main(int argc, char **argv)
{

    printf("old = %s\nnew = %s\n", argv[1], reverseVowels(argv[1]));
}