#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<ctype.h>
# include<limits.h>
# include "libft.h"


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

void    sa(list_t* list_a, int print,list_t *command_list);
void    sb(list_t* list_b, int print,list_t *command_list);
void    ss(list_t* list_a,list_t* list_b, int print,list_t *command_list);
void    pa(list_t* list_a, list_t* list_b, int print,list_t *command_list);
void    pb(list_t* list_a, list_t* list_b, int print,list_t *command_list);
void    ra(list_t* list_a, int print,list_t *command_list);
void    rb(list_t* list_a, int print,list_t *command_list);
void    r(list_t* list_a, list_t *list_b, int print,list_t *command_list);
void    rra(list_t* list_a, int print,list_t *command_list);
void    rrb(list_t* list_b, int print,list_t *command_list);
void    rrr(list_t* list_a, list_t *list_b, int print,list_t *command_list); 
   
node_t* pop_head(list_t* list);
node_t* pop_tail(list_t*list);
void    push_head(list_t* list, node_t* node);
void    push_tail(list_t* list, node_t* node);

void sortlist_a(list_t * list_a, list_t * list_b, int depth,list_t *command_list);
void sortlist_b(list_t * list_b, list_t * list_a, int depth,list_t *command_list);
int get_median(list_t * list, int depth);
int push_big_toa(list_t*list_a, list_t* list_b, int median, int depth,list_t *command_list);
int push_small_tob(list_t*list_a, list_t* list_b, int median, int depth,list_t *command_list);
void smallsort_a(list_t *list_a, int depth,list_t *command_list);
void smallsort_b(list_t *list_b, int depth,list_t *command_list);
void rra_n(list_t* list_a, int n,list_t *command_list);
void rrb_n(list_t* list_b, int n,list_t *command_list);
void pa_n(list_t * list_a, list_t * list_b, int n,list_t *command_list);
void pb_n(list_t * list_b, list_t * list_a, int n,list_t *command_list);

void print_list( list_t * list);
void put_command_in_list(int command, list_t * command_list);
void optimize_commands(list_t *command_list, list_t* optimized_list);
int check_command_replace(int a, int b);
void put_command_in_list(int command, list_t *command_list);

#define SA 1
#define SB 2
#define SS 3
#define PA 4
#define PB 5
#define RA 6
#define RB 7
#define RR 8
#define RRA 9
#define RRB 10
#define RRR 11


#endif