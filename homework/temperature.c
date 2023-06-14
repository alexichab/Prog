#include <stdio.h>
int main()
{
int fahr, celsius;
int lower, upper, step; 

step = 20;
printf("input lower and upper bound (F): ");
scanf ("%d %d", &lower, &upper);

fahr = lower;

while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%3d\t%3d\n", fahr, celsius);
    fahr += step;
    }
    return 0;
}