#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<ctype.h>
# include<limits.h>


// node creation
typedef struct node {
    int val;
    struct node * next;
    struct node* prev;
} node_t;

typedef struct list {
    node_t* head;
    node_t* tail;
} list_t;

list_t  new_list();
node_t* new_node(int value);
list_t  new_list(void);

void	check_input(int argc, char *argv[]);
void   	fill_list_a(int argc, char *argv[], list_t *list_a);
void	check_input_is_only_program_name(int argc);
void	check_input_numbers_are_not_duplicated(int argc, char **argv);
void	check_input_numbers_are_integers(int argc, char *argv[]);
void	check_input_numbers_are_not_overflow(int argc, char *argv[]);
void	check_input_numbers_are_not_underflow(int argc, char *argv[]);

void    sa(list_t* list_a, int print);
void    sb(list_t* list_b, int print);
void    ss(list_t* list_a,list_t* list_b, int print);
void    pa(list_t* list_a, list_t* list_b, int print);
void    pb(list_t* list_a, list_t* list_b, int print);
void    ra(list_t* list_a, int print);
void    rb(list_t* list_a, int print);
void    r(list_t* list_a, list_t *list_b, int print);
void    rra(list_t* list_a, int print);
void    rrb(list_t* list_b, int print);
void    rrr(list_t* list_a, list_t *list_b, int print); 
   
node_t* pop_head(list_t* list);
node_t* pop_tail(list_t*list);
void    push_head(list_t* list, node_t* node);
void    push_tail(list_t* list, node_t* node);


#endif