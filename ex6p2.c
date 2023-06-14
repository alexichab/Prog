#include <stdio.h>
#include <math.h>

int main()
{
    int first;
    int count;
    int sum = 0;
    scanf("%d%d", &first, &count);
    for (int i = 1; i < count + 1; i++)
    {
        printf("%d ", (int)pow(first, i));
        sum += (int)pow(first, i);
    }
    printf("\nСумма: %d", sum);
}