#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "program.h"

int main()  {
    printf("delim: +\n");
    char *paths = malloc(sizeof(char) * 1024);
    char *dir = malloc(sizeof(char) * 256);
    char *username = malloc(sizeof(char) * 32);
    input(paths, dir, username);
    int inputErrors = check(dir, paths, username);
    if(inputErrors != 0) {
        printError(inputErrors);
        return 0;
    }
    char *result = process(paths, dir, username);
    output(result);
    return 0;
}