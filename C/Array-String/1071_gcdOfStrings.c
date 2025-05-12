/*
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t
(i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

static int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

static void concat(char *result, const char *str1, const char *str2) {
    strcat(result, str1);
    strcat(result, str2);
}


char* gcdOfStrings(char* str1, char* str2) {

    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int plus_string = len_str1 + len_str2;

    char *concat1 = calloc(plus_string + 1, sizeof(char));
    if (!concat1)
        return NULL;

    char *concat2 = calloc(plus_string + 1, sizeof(char));
    if (!concat2)
        return NULL;

    concat(concat1, str1, str2);
    concat(concat2, str2, str1);

    if (strcmp(concat1, concat2) != 0)
        return "";
    
    int lenGCD = gcd(len_str1, len_str2);

    char *ret = calloc(lenGCD + 1, sizeof(char));
    if (!ret)
        return NULL;

    strncpy(ret, str1, lenGCD);

    return (ret);
}

int main(int argc, char **argv)
{
    gcdOfStrings(argv[1], argv[2]);
}