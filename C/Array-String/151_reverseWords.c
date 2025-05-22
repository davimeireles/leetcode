#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

static int find_start(char *s)
{
	int i = 0;
	while (isspace(s[i]))
		i++;
	return i;
}

static int find_end(char *s)
{
	int i = strlen(s) - 1;
	while (isspace(s[i]))
		i--;
	return i;
}

static int count_words(char *s)
{
	int i = 0;
	int cw = 0;

	while (s[i])
	{
		while (s[i] && isspace(s[i]))
			i++;

		if (s[i])
			cw++;

		while (s[i] && !isspace(s[i]))
			i++;
	}

	return cw;
}

static char *trim(char *s)
{
	int start = find_start(s);
	int end = find_end(s);
	int total_size = end - start + 1;
	char *trimmed_str = calloc(total_size + 1, sizeof(char));

	if (!trimmed_str)
		return NULL;

	int i = 0;
	while (start <= end)
	{
		trimmed_str[i] = s[start];
		i++;
		start++;
	}
	trimmed_str[i] = '\0';
	return trimmed_str;
}

char *reverseWords(char *s)
{
	char *trimmed;

	trimmed = trim(s);

	if (strlen(trimmed) == 1)
		return trimmed;

	int count_letters = 0;
	int j = 0;
	int i = 0;
	int cw = count_words(trimmed);
	while (trimmed[i])
	{
		if (!isspace(trimmed[i]))
			count_letters++;
		i++;
	}

	char *ret = calloc(count_letters + (cw - 1) + 1, sizeof(char));
	if (!ret)
		return NULL;

	i = strlen(trimmed) - 1;
	int start;
	int end = i;
	while (i > 0)
	{
		while (i > 0 && isspace(trimmed[i]))
			i--;
		end = i;
		while (i > 0 && !isspace(trimmed[i]))
			i--;
		start = i;
		if (isspace(trimmed[start]))
			start++;
		while (start <= end)
		{
			ret[j] = trimmed[start];
			j++;
			start++;
		}
		if (cw > 1)
		{
			ret[j++] = ' ';
			cw--;
		}
	}
	ret[j] = '\0';
	free(trimmed);
	return ret;
}
