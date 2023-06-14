#include "strings.h"
#include <stdio.h>
#include <stdlib.h>

char *scpy(const char *src, char *des) //копирует строку
{
	int i;
	for (i = 0; src[i] != 0; i++) {
		des[i] = src[i];
	}
	des[i] = 0;
	return des;
}

int slen(const char *str) //длину возвращает строки
{
	int count = 0;;
	for (int i = 0; str[i] != '\0'; i++) {
		count++;
	}
	return ++count;
}

int scmp(const char *s1, const char *s2) //сравнивает строки
{
	char c1, c2;
	while(1) {
		c1 = *s1++;
		c2 = *s2++;
		if(c1 > c2) {
			return 1;
		} else if(!c1) {
			break;
		} else {
			return -1;
		}
	}
	return 0;
}

char *scat(char *dest, const char *src) //вставляют одну строку в конец другой
{
	char *end = dest + slen(dest) - 1;
	while(*src != '\0') {
		*end++ = *src++;
	}
	*end = '\0';
	return dest;
}

char *schr(const char *s, const char c) //ищет первое вхождение символа в строку
{
	while(*s && *s != c) {
		++s;
	}
	return (*s) ? (char*)s : NULL;
}

char *stok(char *str, const char *delim) // разделение на токены
{
	static char *next;
	if(str) {
		next = str;
		while(*next && schr(delim, *next)) {
			*next++ = '\0';
		}
	}
	if(!*next) {
		return NULL;
	}
	str = next;
	while(*next && !schr(delim, *next)) {
		++next;
	}
	while(*next && schr(delim, *next)) {
		*next++ = '\0';
	}
	return str;
}

char* sstr(char s1[254], char s2[254]) // находит первое вхождение одной строки в другую
{
	if(*s2 == '\0') {
		return s1;
	}
	char *ptr;
	for(int i = 0; i < slen(s1); i++) {
		if(*(s1+i) == *s2) {
			ptr = sstr(s1+i+1, s2+1);
			return (ptr) ? ptr-1 : NULL;
		}
	}
	return NULL;
}
