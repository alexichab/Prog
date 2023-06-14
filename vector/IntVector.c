#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector *t = malloc(sizeof(IntVector));
    if (t == NULL)
    {
        printf("Error! 't'");
        return NULL;
    }
    t->data = malloc(initial_capacity * sizeof(int));
    if (t->data == NULL)
    {
        printf("Error! 't->data'");
        return NULL;
    }
    t->size = 0;
    t->capacity = initial_capacity;
    return t;
}
IntVector *int_vector_copy(const IntVector *v)
{
    IntVector *t = malloc(sizeof(IntVector));
    if (t == NULL)
    {
        printf("Error! 't'");
        return NULL;
    }
    t->data = malloc(v->capacity * sizeof(int));
    if (t->data == NULL)
    {
        printf("Error! 't->data'");
        return NULL;
    }
    memcpy(t->data, v->data, v->capacity * sizeof(int));
    t->size = v->size;
    t->capacity = v->capacity;
    return t;
}
void int_vector_free(IntVector *v)
{
    free(v->data);
    free(v);
}
int int_vector_get_item(const IntVector *v, size_t index)
{
    if (index <= v->size)
    {
        return v->data[index];
    }
    else
        return -1;
}
void int_vector_set_item(IntVector *v, size_t index, int item)
{
    if (index => v->size)
      printf("ERROR");
    else
      v->data[index] = item;
}
size_t int_vector_get_size(const IntVector *v)
{
    return v->size;
}
size_t int_vector_get_capacity(const IntVector *v)
{
    return v->capacity;
}
int int_vector_push_back(IntVector *v, int item)
{
    if (v->size < v->capacity)
    {
        v->data[v->size] = item;
        v->size++;
    }
    else
    {
        v->capacity++;
        v->capacity *= 2;
        int *t = realloc(v->data, v->capacity * sizeof(int));
        if (t == NULL)
            return -1;
        v->data = t;
        v->data[v->size] = item;
        v->size++;
    }
    return 0;
}
void int_vector_pop_back(IntVector *v)
{
    if (v->size != 0)
        v->size--;
}
int int_vector_shrink_to_fit(IntVector *v)
{
    if (v->size == 0)
    {
        free(v->data);
        v->data = NULL;
        v->capacity = v->size;
        return 0;
    }
    if (v->size != v->capacity)
    {
        int *t = realloc(v->data, sizeof(int) * v->size);
        if (t == NULL)
        {
            printf("Error!");
            return -1;
        }
        v->data = t;
        v->capacity = v->size;
    }
    return 0;
}
int int_vector_resize(IntVector *v, size_t new_size)//new_size> capacity print error!!!
{
    if (new_size > v->size)
    {
        if (new_size > v->capacity)
        {
            int k;
            ++v->capacity;
            for (k = 2; k * (v->capacity) < new_size; k *= 2)
                ;
            int *t = realloc(v->data, sizeof(int) * (v->capacity) *
                                          k);
            if (t == NULL)
            {
                --v->capacity;
                printf("Error!");
                return -1;
            }
            v->data = t;
            v->capacity *= k;
            for (k = v->size; k < new_size; ++k)
            {
                v->data[k] = 0;
            }
            v->size = new_size;
        }
        else
        {
            for (int k = v->size; k < new_size; ++k)
            {
                v->data[k] = 0;
            }
            v->size = new_size;
        }
    }
    if (new_size < v->size)
    {
        for (int i = new_size; i < v->size; ++i)
        {
            v->data[i] = 0;
        }
        v->size = new_size;
    }
    return 0;
}
int int_vector_reserve(IntVector *v, size_t new_capacity)
{
    if (new_capacity > v->capacity)
    {
        int *t = realloc(v->data, sizeof(int) * new_capacity);
        if (t == NULL)
        {
            printf("Error!");
            return -1;
        }
        v->data = t;
        v->capacity = new_capacity;
    }
    return 0;
}
void print_intvector(IntVector *v)
{
    printf("Vector: ");
    for (int i = 0; i < int_vector_get_size(v); ++i)
    {
        printf("%d ", int_vector_get_item(v, i));
    }
    printf("\n");
    printf("Size:%3ld\nCapacity:%ld\n",int_vector_get_size(v),int_vector_get_capacity(v));
}
