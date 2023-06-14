#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "program.h"

// int checkPaths(char *paths) {
//     char *path = stok(paths, "+");
//     static int code = 0;
//     while(path != NULL) {
//         if(code != 0) {
//             continue;
//         }
//         if(path[0] != '/' && path[0] != '~') {
//             code = -5;
//         } else if(path[slen(path)-1] == '/') {
//             code = -6;
//         } else if(sstr(path, "\\") != NULL) {
//             code = -7;
//         } else if(slen(path) > 255) {
//             code = -8;
//         }
//         path = stok(NULL, "+");
//     }
//     return code;
// }


void input(char *paths, char *dir, char *username)
{
    printf("username: ");
	scanf(" %[^\n]", username);
    printf("dir: ");
	scanf(" %[^\n]", dir);
	printf("old paths: ");
	scanf(" %[^\n]", paths);
}

int check(char *dir, char *paths, char *username) {
    if(dir == NULL || paths == NULL || username == NULL) {
        return -1;
    } else if(dir[0] != '/' || !isalpha(username[0])) {
        return -2;
    } else if(dir[slen(dir)-1] == '/' || username[slen(username)-1] == '/') {
        return -3;
    } else if(slen(dir) < 2 || slen(username) < 4 || slen(paths) < 2) {
        return -4;
    } else if(slen(dir) > 255 || slen(username) > 31) {
        return -8;
    } else {
        return 0;
    }
}

void printError(int inputErrors) {
    printf("ERROR: ");
    switch(inputErrors) {
        case -1:
            printf("some of arguments doesn't exist\n");
            break;
        case -2:
            printf("bad dir character\n");
            break;
        case -3:
            printf("bad last character\n");
            break;
        case -4:
            printf("too short argument\n");
            break;
        case -5:
            printf("bad path beginning\n");
            break;
        case -6:
            printf("path ending error\n");
            break;
        case -7:
            printf("bad character in path\n");
            break;
        case -8:
            printf("too long argument\n");
            break;
        }
}

char* process(char* paths, char* dir, char* username) {
    int size = slen(paths) + 1;
    char *result = malloc(size * sizeof(char));

    char *user = malloc(sizeof(char) * (slen(username) + 1));
    scat(user, "~");
    scat(user, username);

    char *delim = "+";
    char *path = stok(paths, delim);
    while(path != NULL) {
        if(path[0] == '~' && path[1] == '/') {
            char *userdir = malloc(sizeof(char) * (slen(dir) + slen(username) + 1));
            scat(userdir, dir);
            scat(userdir, "/");
            scat(userdir, username);
            size += slen(userdir);
            result = realloc(result, size * sizeof(char));
            scat(result, userdir);
            scpy(&path[1], path);
            free(userdir);
        } else if(sstr(path, user) != NULL) {
            size += slen(dir);
            result = realloc(result, size * sizeof(char));
            scat(result, dir);
            scat(result, "/");
            scpy(&path[1], path);
        }
        scat(result, path);
        path = stok(NULL, delim);
        if(path != NULL) {
            scat(result, delim);
        }
    }
    return result;
}

void output(char *newPaths) {
    printf("new paths: %s\n", newPaths);
}