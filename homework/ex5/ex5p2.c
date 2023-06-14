#include <stdio.h>
#include <locale.h>
 
int main()
{
int number, month;
 
setlocale(LC_ALL, "russian");
printf("Введите день рождения:");
scanf("%d",&number);
printf("Введите месяц рождения:");
scanf("%d",&month);
switch(month){
    case 1:
        if(number<=20){
            printf("Козерог");
        }
        else{
            printf("Водолей");
        }
        break;
        case 2:
        if(number<=20){
            printf("Водолей");
        }
        else{
            printf("Рыба");
        }
        break;
        case 3:
        if(number<=20){
            printf("Рыба");
        }
        else{
            printf("Овен");
        }
        break;
                case 4:
        if(number<=20){
            printf("Овен");
        }
        else{
            printf("Телец");
        }
        break;
                case 5:
        if(number<=20){
            printf("Телец");
        }
        else{
            printf("Близнецы");
        }
        break;
                case 6:
        if(number<=21){
            printf("Близнецы");
        }
        else{
            printf("Рак");
        }
        break;
                case 7:
        if(number<=22){
            printf("Рак");
        }
        else{
            printf("Лев");
        }
        break;
                case 8:
        if(number<=23){
            printf("Лев");
        }
        else{
            printf("Дева");
        }
        break;
                case 9:
        if(number<=23){
            printf("Дева");
        }
        else{
            printf("Весы");
        }
        break;
                case 10:
        if(number<=23){
            printf("Весы");
        }
        else{
            printf("Скорпион");
        }
        break;
                case 11:
        if(number<=22){
            printf("Скорпион");
        }
        else{
            printf("Стрелец");
        }
        break;
                case 12:
        if(number<=20){
            printf("Стрелец");
        }
        else{
            printf("Козерог");
        }
        break;
        
    default :
                printf("Всего 12 месяцев");
        break;
        
        }       
}