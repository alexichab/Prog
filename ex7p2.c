#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

char *read()
{
    char *str = NULL;
    int ch;
    size_t size = 0, length = 0;
    while ((ch = getchar()) != EOF && ch != '\n')
    {
        if (length + 1 >= size)
        {
            size = size * 2 + 1;
            str = realloc(str, size);
        }
        str[length++] = ch;
    }
    if (str != NULL)
    {
        str[length] = '\0';
        return str;
    }
    return NULL;
}

char *transform(char *data)
{
    char *out = malloc(strlen(data));
    for (int i = 0, j = 0; i < strlen(data); i++)
    {
        if (isalnum(data[i]))
        {
            out[j] = tolower(data[i]);
            j++;
        }
    }
    return out;
}

bool is_palindrome(char *data)
{
    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] != data[strlen(data) - i - 1])
        {
            return false;
        }
    }
    return true;
}

void main() /*Never odd or even*/
{
    char *str = read();
    if (!str)
    {
        fputs("Error. Empty string.\n", stdout);
        exit(EXIT_FAILURE);
    }

    fputs("is palindrome: ", stdout);
    char *transformed = transform(str);
    free(str);
    fputs(is_palindrome(transformed) ? "true\n" : "false\n", stdout);
    free(transformed);
}
