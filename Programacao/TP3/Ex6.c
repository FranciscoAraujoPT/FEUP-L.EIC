#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct _node
{
    int value;
    struct _node *prev;
    struct _node *next;
};
typedef struct _node node;

typedef struct
{
    int size;
    node *first;
    node *last;
} ilist;

ilist *l_create(void)
{
    ilist *l = malloc(sizeof(ilist));
    l->size = 0;
    l->first = NULL;
    l->last = NULL;
    return l;
}

void l_destroy(ilist *l)
{
    node *n = l->first, *n2;
    while (n != NULL)
    {
        n2 = n->next;
        free(n);
        n = n2;
    }
    free(l);
}

int l_size(ilist *l)
{
    return l->size;
}

void l_print(const ilist *l)
{
    node *n = l->first;
    printf("-- (%d elements) --\n", l->size);
    while (n != NULL)
    {
        printf("[%p] value: %d prev: %p next: %p\n",
               n,
               n->value,
               n->prev,
               n->next);
        n = n->next;
    }
    printf("-\n");
}

void l_add_first(ilist *l, int value)
{
    node *new_node = calloc(1, sizeof(node));
    new_node->value = value;
    new_node->prev = l->last;
    if (l->size == 0)
    {
        l->first = l->last = new_node;
    }
    else
    {
        new_node->next = l->first;
        l->first->prev = new_node;
        l->first = new_node;
    }
    l->size++;
}

void l_add_last(ilist *l, int value)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    if (l->size == 0)
    {
        new_node->prev = NULL;
        l->first = l->last = new_node;
    }
    else
    {
        new_node->prev = l->last;
        l->last->next = new_node;
        l->last = new_node;
    }
    l->size++;
}

bool l_remove_first(ilist *l, int *pvalue)
{
    if (l == NULL)
    {
        return false;
    }

    *pvalue = l->first->value;
    node *aux = l->first;
    l->first = l->first->next;
    free(aux);
    l->size--;

    return true;
}

bool l_remove_last(ilist *l, int *pvalue)
{
    if (l == NULL)
    {
        return false;
    }

    *pvalue = l->last->value;
    node *aux = l->last;
    l->last = l->last->prev;

    free(aux);

    l->size--;

    return true;
}

int main(void)
{
    const int n = 5;
    ilist *l = l_create();
    l_print(l);
    for (int i = 0; i < n; i++)
    {
        int v = i * 100;
        l_add_last(l, v);
        printf("Value added: %d\n", v);
    }
    l_print(l);

    for (int i = 0; i < n; i++)
    {
        int v;
        l_remove_first(l, &v);
        printf("Value removed: %d\n", v);
    }
    l_print(l);

    l_destroy(l);
}