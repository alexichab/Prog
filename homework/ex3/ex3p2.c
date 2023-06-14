
#include <stdio.h>
#include <math.h>
int main() 
{
    printf("\tdec\t\thext\toct\t\tchar\t\n");
    for (int i = 0; i < 128; i++)
{
    printf("\t%d\t\t%hhx\t\t%o\t\t%c\t\n",i,i,i, (i<32 || i >126) ? ' ' : i);
}


return 0;
}


