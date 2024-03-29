#include "push_swap.h"

void	check_input(int argc, char *argv[])
{
	check_input_is_only_program_name(argc);
	check_input_numbers_are_integers(argc, argv);
	check_input_numbers_are_not_overflow(argc, argv);
	check_input_numbers_are_not_underflow(argc, argv);
	check_input_numbers_are_not_duplicated(argc, argv);
}


void   	fill_list_a(int argc, char *argv[], list_t *list_a)
{
    list_a->head = new_node(ft_atoi(argv[1]));
    list_a->tail = list_a->head;

    int i = 2;
    while (i < (argc))
    {
        node_t * nod = new_node(ft_atoi(argv[i]));
        nod->prev = list_a->tail;
        list_a->tail->next = nod;
        list_a->tail = nod;
        i++;
    }
}


