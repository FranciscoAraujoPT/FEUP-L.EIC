#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;    // Elementos
    int capacity; // Capacidade do array
    int size;     // Nº de elementos (posições ocupadas)
} ivector;

ivector *v_create(int initial_capacity)
{
    ivector *v = malloc(sizeof(ivector));
    v->data = malloc(initial_capacity * sizeof(int));
    v->capacity = initial_capacity;
    v->size = 0;
    return v;
}

int v_size(ivector *v)
{
    if (v == NULL)
    {
        return -1;
    }

    return v->size;
}

int *v_data(ivector *v)
{
    if (v == NULL)
    {
        return NULL;
    }

    return v->data;
}

void v_destroy(ivector *v)
{
    if (v == NULL)
    {
        return;
    }

    free(v->data);
    free(v);
}

void v_add(ivector *v, int x)
{
    if (v == NULL)
    {
        return;
    }

    v->size++;
    if (v->size == v->capacity)
    {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }

    v->data[v->size - 1] = x;
}

int compare_int(const void *v1, const void *v2)
{
    return (*(int *)v1) - (*(int *)v2);
}

void sort_int_array(int a[], int n)
{
    qsort(a, n, sizeof(int), &compare_int);
}

int main(void)
{

    ivector *v = v_create(1);
    printf("Enter values: ");

    int aux;
    while (scanf("%d", &aux) != EOF)
    {
        v_add(v, aux);
        if (v->data[v->size - 1] == 0)
        {
            break;
        }
    }

    v->size--;
    if (v_size(v) > 0)
    {
        sort_int_array(v->data, v->size);
        printf("Median: %f\n", v->size % 2 != 0 ? (float)v->data[v->size / 2] : (float)(v->data[v->size / 2] + v->data[v->size / 2 - 1]) / 2);
    }

    v_destroy(v);
    return 0;
}