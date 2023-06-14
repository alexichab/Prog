#include <stdio.h>
#include <string.h>
#include "IntVector.h"

int main()
{
    int i;
    IntVector *vec, *vecp;
    vec = int_vector_new(3);
    printf("Создание вектора\n");
    print_intvector(vec);
    printf("\n\n");
    for (i = 1; i < 5; ++i)
    {
        printf("Добавим в конец вектора %d\n", i);
        int_vector_push_back(vec, i);
        print_intvector(vec);
        printf("\n");
    }
    printf("\n");
    printf("Скопированный вектор\n");
    vecp = int_vector_copy(vec);
    print_intvector(vecp);
    printf("\n\n");
    printf("Получим элемент в пределах вектора\n2 индекс = %d\n\n",
           int_vector_get_item(vecp, 2));
    printf("Получим элемент за пределами вектора\n");
    printf("6 индекс = %d\n", int_vector_get_item(vecp, 6));
    printf("\n\n");
    printf("Установим новое значение элементу с индексом 2\n");
    print_intvector(vecp);
    int_vector_set_item(vecp, 2, 22);
    print_intvector(vecp);
    printf("\n");
    printf("Установим новое значение элементу с индексом 6\n");
    int_vector_set_item(vecp, 6, 22);
    print_intvector(vecp);
    printf("\n\n");
    printf("Получим размер массива\n");
    printf("Size = %zu\n\n", int_vector_get_size(vecp));

    printf("Получим объем массива\n");
    printf("Capacity = %zu\n", int_vector_get_capacity(vecp));
    printf("\n\n");
    for (i = 0; i < 2; ++i)
    {
        printf("Удалим %d элемент\n", 4 - i);
        print_intvector(vecp);
        int_vector_pop_back(vecp);
        print_intvector(vecp);
        printf("\n");
    }
    printf("\n");
    printf("Уменьшим объем до размера\n");
    print_intvector(vecp);
    int_vector_shrink_to_fit(vecp);
    print_intvector(vecp);
    printf("\n\n");
    printf("Изменим размер: new size(5) > size\n");
    print_intvector(vecp);
    int_vector_resize(vecp, 5);
    print_intvector(vecp);
    printf("\n");
    printf("Изменим размер: new size(1) < size\n");
    print_intvector(vecp);
    int_vector_resize(vecp, 1);
    print_intvector(vecp);
    printf("\n\n");
    printf("Изменим объем: new capacity(10) > capacity\n"); 
    print_intvector(vecp);
    int_vector_reserve(vecp, 10);
    print_intvector(vecp);
    printf("\n");
    printf("Изменим объем: new capacity(1) < capacity\n");
    print_intvector(vecp);
    int_vector_reserve(vecp, 1);
    print_intvector(vecp);
    printf("\n\n");
    int_vector_resize(vecp, 0);
    int_vector_shrink_to_fit(vecp);
    printf("Изменим размер при size = 0 и capacity = 0: newsize(1)\n");
    print_intvector(vecp);
    int_vector_resize(vecp, 1);
    print_intvector(vecp);
    printf("\n\n");
    int_vector_resize(vecp, 0);
    int_vector_shrink_to_fit(vecp);
    printf("Добавим элемент в конец вектора при size = 0 и capacity = 0\n");
    print_intvector(vecp);
    int_vector_push_back(vecp, 10);
    print_intvector(vecp);
    printf("\n\n");
    int_vector_free(vecp);
    int_vector_free(vec);
    return 0;
}

