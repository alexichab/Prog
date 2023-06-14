#pragma once

void input(char *paths, char *dir, char *username);
int check(char *dir, char *paths, char *username);
void printError(int inputErrors);
char* process(char* paths, char* dir, char* username);
void output(char *newPaths);
int checkPaths(char *paths);