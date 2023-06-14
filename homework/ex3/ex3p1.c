#include <stdio.h>
#include <math.h>

int main()
{
    int  a, b, c, P, P2, S;
    printf("Введите первую сторону:\n");
    scanf("%d", &a);
    printf("Введите вторую сторону:\n");
    scanf("%d", &b);
    printf("Введите третью сторону:\n");
    scanf("%d", &c);
    if (a+b < c || a+c < b || b+c <a ){
    printf("Ваш треугольник не существует\n");
    } 
    else {
    P = a+b+c;
    P2 =P/2;
    S =sqrt(P2*(P2-a)*(P2-b)*(P2-c));
    printf("Периметр = %d \n", P);
    printf("Площадь = %d \n", S);
    }

    return 0;
}