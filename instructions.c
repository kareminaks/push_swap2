#include "push_swap.h"

//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.

void sa(list_t* list_a, int print)
{
    // printf("a before:\n");
    // print_list(list_a);
    if (print)
    printf("sa\n");

    if ((list_a->head == list_a->tail) || (!list_a->head)) {
        return;
    }
    node_t* top = pop_head(list_a);
    node_t* prev = pop_head(list_a);
    push_head(list_a, top);
    push_head(list_a, prev);

    // printf("a after:\n");
    // print_list(list_a);
}
//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
void sb(list_t* list_b, int print)
{
    // printf("b before:\n");
    // print_list(list_b);
    if (print)
    printf("sb\n");

    if ((list_b->head == list_b->tail) || (!list_b->head)) {
        return;
    }
    node_t* top = pop_head(list_b);
    node_t* prev = pop_head(list_b);
    push_head(list_b, top);
    push_head(list_b, prev);
}

//ss : sa and sb at the same time.
void ss(list_t* list_a,list_t* list_b, int print)
{
    if (print)
    printf("ss\n");
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
        list->head->prev = 0;
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
        list->tail->next = 0;
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
    // printf("a before:\n");
    // print_list(list_a);
    // printf("b before:\n");
    // print_list(list_b);
    if (print) 
        printf("pa\n");
    node_t* head = pop_head(list_b);
    if (!head) return;
    push_head(list_a, head);
}

//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.

void pb(list_t* list_b, list_t* list_a, int print)
{
    // printf("a before:\n");
    // print_list(list_a);
    // printf("b before:\n");
    // print_list(list_b);
    if (print)
    printf("pb\n");
    node_t* head = pop_head(list_a);
    if (!head) return;
    push_head(list_b, head);
}

//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.
void ra(list_t* list_a, int print)
{
    // printf("a before:\n");
    // print_list(list_a);
    if (print)
    printf("ra\n");
    node_t* head = pop_head(list_a);
    if (!head) return;
    push_tail(list_a, head);
}
//rb (rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one.
void rb(list_t* list_b, int print)
{
    // printf("b before:\n");
    // print_list(list_b);
    if (print)
    printf("rb\n");
    node_t* head = pop_head(list_b);
    if (!head) return;
    push_tail(list_b, head);
}
//rr : ra and rb at the same time.
void rr(list_t* list_a, list_t *list_b, int print){
    if (print)
    printf("rr\n");

    ra(list_a, 0);
    rb(list_b, 0);
}

//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
void rra(list_t* list_a, int print){
    // printf("a before:\n");
    // print_list(list_a);

    // printf("head.next=%p head.prev=%p tail.next=%p tail.prev=%p\n",
    //     list_a->head->next, list_a->head->prev, list_a->tail->next, list_a->tail->prev);

    if (print)
    printf("rra\n");
    node_t* tail = pop_tail(list_a);
    if(!tail) return;
    push_head(list_a, tail);
}

//rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
void rrb(list_t* list_b, int print){
    // printf("b before:\n");
    // print_list(list_b);
    if (print)
    printf("rrb\n");
    node_t* tail = pop_tail(list_b);
    if(!tail) return;
    push_head(list_b, tail);
}
//rrr : rra and rrb at the same time
void rrr(list_t* list_a, list_t *list_b, int print){
    if (print)
    printf("rrr\n");

    rra(list_a, 0);
    rrb(list_b, 0);
}