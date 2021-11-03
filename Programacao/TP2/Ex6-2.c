#include <stdio.h>
#include <stdbool.h>

#define MAX_ELEMENTS 5

typedef struct
{
    int elements[MAX_ELEMENTS];
    int size;
} stack;

void stack_init(stack *s)
{
    s->size = 0;
}

int stack_size(const stack *s)
{
    return s->size;
}

bool stack_is_empty(const stack *s)
{
    if (stack_size(s) == 0)
    {
        return true;
    }

    return false;
}

bool stack_is_full(const stack *s)
{
    if (stack_size(s) == MAX_ELEMENTS)
    {
        return true;
    }

    return false;
}

bool stack_push(stack *s, int v)
{
    if (stack_is_full(s))
    {
        return false;
    }

    s->elements[s->size] = v;
    s->size++;

    return true;
}

bool stack_pop(stack *s, int *v)
{
    if (stack_is_empty(s))
    {
        return false;
    }

    s->size--;
    *v = s->elements[s->size];
    s->elements[s->size] = 0;

    return true;
}

void stack_print(const stack *s)
{
    printf("[");
    for (int i = 0; i < s->size; i++)
    {
        printf(" %d", s->elements[i]);
    }
    printf(" ] (%d elements; empty: %d; full: %d)\n",
           stack_size(s),
           stack_is_empty(s),
           stack_is_full(s));
}

int main(void)
{
    stack s;
    stack_init(&s);
    stack_print(&s);
    for (int i = 0; i <= MAX_ELEMENTS; i++)
    {
        bool r = stack_push(&s, i * 100);
        if (r)
        {
            printf("value pushed\n");
        }
        else
        {
            printf("value not pushed - stack is full!\n");
        }
        stack_print(&s);
    }

    for (int i = 0; i <= MAX_ELEMENTS; i++)
    {
        int v;
        bool r = stack_pop(&s, &v);
        if (r)
        {
            printf("value popped: %d\n", v);
        }
        else
        {
            printf("value not popped - stack is empty!\n");
        }
        stack_print(&s);
    }
    return 0;
}