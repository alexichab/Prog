#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int i, allLetterNum = 0, symbolNum = 0, vowelLettersNum = 0, digitsNum = 0, marksNum = 0, lettersPercent = 0;
    char vowel[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    char marks[6] = {',', '.', '!', '?', ':', '-'};
    char symbol;

    while ((symbol = getchar()) != '\n') {
        if (symbol != ' ') {
            symbolNum++;
        }
        if (isalpha(symbol)) {
            allLetterNum++;

            for (i = 0; i < strlen(vowel); i++) {
                if (tolower(symbol) == vowel[i]) {
                    vowelLettersNum++;
                    break;
                }
            }
        } else if (isdigit(symbol)) {
            digitsNum++;
        } else {
            for (i = 0; i < strlen(marks); i++) {
                if (symbol == marks[i]) {
                    marksNum++;
                }
            }
        }
    }

    lettersPercent = allLetterNum * 100 / symbolNum;
    printf("Знаков препинания: %d\n", marksNum);
    printf("Гласных букв: %d\n", vowelLettersNum);
    printf("Процент букв: %d%%\n", lettersPercent);
    printf("Цифр: %d\n", digitsNum);
    
    return 0;
}