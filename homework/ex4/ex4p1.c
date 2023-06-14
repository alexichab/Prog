#include <stdio.h>
#include <math.h>
 
int main (void)
{ 
    char end, i, ch, c;
    char start = 'A';
    int size;
    
    printf("Введите любую заглавную букву английского регистра: ");
    scanf("%c", &end);
 
    size = end - start;
 
    for (i = start; i <= end; ++i, --size)
        {
            for (c = 0; c < size; ++c)
                printf(" ");
 
            for (ch = start; ch <= i; ++ch)
                printf("%c", ch);
 
            for (ch = ch - 2; ch >= start; --ch)
                printf("%c", ch);
 
            printf("\n");
        }
    return 0;
}