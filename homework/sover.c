#include <stdio.h>

int main() 
{
int i,sum,d;
for  (i=2; i < 10000; i++)
{
sum = 1;
for (d = 2; d < i-1;d++)
if (i%d == 0)
sum += d;
if (sum == i)
printf("%d\n", i);
}
return 0;
}
