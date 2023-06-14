#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    size_t left;
    size_t right;
} Bounds;

static void print(int *data, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

static void swap(int *item1, int *item2)
{
    *item1 ^= *item2;
    *item2 ^= *item1;
    *item1 ^= *item2;
}

static Bounds get_bounds(int *data, int size)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
        if (data[i] > max)
        {
            max = data[i];
        }
    }
    Bounds t = {min, max};
    return t;
}

//лучше подойдет для специфичных данных в случае мелкого размера буфера
void counting_sort(int *data, int size)
{
    //находим границы массива (минимальный и максимальный элементы)
    Bounds bounds = get_bounds(data, size);
    int min = bounds.left, max = bounds.right;
    int *counts = malloc(sizeof(int) * (max - min + 1));

    //находим кол-во каждого элемента
    for (int i = 0; i < size; i++)
    {
        counts[data[i] - min]++;
    }
    //сортируем
    for (int j = min, k = 0; j <= max; j++)
    {
        for (int i = 0; i < counts[j - min]; i++)
        {
            data[k++] = j;
        }
    }
    free(counts);
}

void insertion_sort(int *data, int size, int *out)
{
    (*out) = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (data[j] < data[j - 1])
            {
                swap(&data[j], &data[j - 1]);
                (*out)++;
                continue;
            }
            break;
        }
    }
}

int main()
{
    //объявляем массив
    int arr2[] = {9, -1, 8, 9, 4, 11, 6, 7, -11, 5};
    //получаем размер массива в байтах, делим на размер элемента, получаем кол-во элементов
    int size = sizeof(arr2) / sizeof(int);
    //счетчик операций
    int count;
    print(arr2, size);
    //вставками
    insertion_sort(arr2, size, &count);
    print(arr2, size);
    printf("\n%i\n", count);

    printf("\n========\n");

    int arr3[] = {9, 1, 8, 9, 4, 11, 6, 7, 14, 5};
    print(arr3, size);
    //подсчетом
    counting_sort(arr3, size);
    print(arr3, size);
}
