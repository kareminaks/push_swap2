#include "push_swap.h"

//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.

void sa(list_t* list_a, int print)
{
    int n;
    if (print = 1)
    ft_printf("sa\n");

    if ((list_a->head == list_a->tail) || (!list_a->head)) {
        return;
    }
    n = list_a->head->val;
    list_a->head->val = list_a->head->prev->val;
    list_a->head->prev->val = n;
}
//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
void sb(list_t* list_b, int print)
{
    int n;
    if (print = 1)
    ft_printf("sb\n");

    if ((list_b->head == list_b->tail) || (!list_b->head)) {
        return;
    }
    n = list_b->head->val;
    list_b->head->val = list_b->head->prev->val;
    list_b->head->prev->val = n;
}

//ss : sa and sb at the same time.
void ss(list_t* list_a,list_t* list_b, int print)
{
    if (print = 1)
    ft_printf("ss\n");
    sa(list_a, 0);
    sb(list_b, 0);
}

node_t* pop_head(list_t* list) {
 if (!list->head) {
        return 0;
    }

    node_t* node = list->head;
    if (list->head == list->tail) {
        list->head = 0;
        list->tail = 0;
     } 
    else {
        list->head = node->next;
    }
    node->prev = 0;
    node->next = 0;
    return node;
}

node_t* pop_tail(list_t*list)
{
     if (!list->tail) {
        return 0;
    }

    node_t* node = list->tail;
    if (list->head == list->tail) {
        list->head = 0;
        list->tail = 0;
     } 
    else {
        list->tail = node->prev;
    }
    node->prev = 0;
    node->next = 0;
    return node;
}

void push_head(list_t* list, node_t* node)
{
    if (list->head == 0) {
        list->head = node;
        list->tail = node;
        node->prev = 0;
        node->next = 0;
    } else {
        list->head->prev = node;
        node->next = list->head;
        list->head = node;
        node->prev = 0;
    }
}

void push_tail(list_t* list, node_t* node)
{
    if (list->tail == 0) {
        list->head = node;
        list->tail = node;
        node->prev = 0;
        node->next = 0;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
        node->next = 0;
    }
}
//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
void pa(list_t* list_a, list_t* list_b, int print)
{
    if (print = 1)
    ft_printf("pa\n");
    node_t* head = pop_head(list_b);
    if (!head) return;
    push_head(list_a, head);
}

//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.

void pb(list_t* list_a, list_t* list_b, int print)
{
    if (print = 1)
    ft_printf("pb\n");
    node_t* head = pop_head(list_a);
    if (!head) return;
    push_head(list_b, head);
}

//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.
void ra(list_t* list_a, int print)
{
    if (print = 1)
    ft_printf("ra\n");
    node_t* head = pop_head(list_a);
    if (!head) return;
    push_tail(list_a, head);
}
//rb (rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one.
void rb(list_t* list_a, int print)
{
    if (print = 1)
    ft_printf("rb\n");
    node_t* head = pop_head(list_a);
    if (!head) return;
    push_tail(list_a, head);
}
//rr : ra and rb at the same time.
void rr(list_t* list_a, list_t *list_b, int print){
    if (print = 1)
    ft_printf("rr\n");

    ra(list_a, 0);
    rb(list_b, 0);
}

//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
void rra(list_t* list_a, int print){
    if (print = 1)
    ft_printf("rra\n");
    node_t* tail = pop_tail(list_a);
    if(!tail) return;
    push_head(list_a, tail);
}

//rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
void rrb(list_t* list_b, int print){
    if (print = 1)
    ft_printf("rrb\n");
    node_t* tail = pop_tail(list_b);
    if(!tail) return;
    push_head(list_b, tail);
}
//rrr : rra and rrb at the same time
void rrr(list_t* list_a, list_t *list_b, int print){
    if (print = 1)
    ft_printf("rrr\n");

    rra(list_a, 0);
    rrb(list_b, 0);
}