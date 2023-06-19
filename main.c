#include "push_swap.h"

int	main(int argc, char **argv)
{

	check_input(argc, argv);
	list_t list_a = new_list();
	list_t list_b = new_list();
	list_t command_list = new_list();
	command_list.head = new_node(0);
    command_list.tail = command_list.head;
	list_t optimized_list = new_list();
	fill_list_a(argc, argv, &list_a);
	sortlist_a( &list_a ,&list_b, argc-1, &command_list);
	optimize_commands(&command_list, &optimized_list);
	print_list(&optimized_list);
}

void print_list( list_t * list)
{
	if (!list)
	{
		printf("nil");
		return;
	}
	printf("head=%p tail=%p\n", list->head, list->tail);
	if (list->head == 0)
		return;

	if (list->head->prev)
		printf("ACHTUNG: head->prev != 0\n");
	if (list->tail->next)
		printf("ACHTUNG: tail->next != 0\n");
	node_t* ptr=list->head;
	while (ptr!= 0)
	{
		if (ptr->val ==SA)
		printf("sa");
		else if (ptr->val ==SB)
		printf("sb");
		else if (ptr->val ==SS)
		printf("ss");
		else if (ptr->val ==PA)
		printf("pa");
		else if (ptr->val ==PB)
		printf("pb");
		else if (ptr->val ==RA)
		printf("ra");
		else if (ptr->val ==RB)
		printf("rb");
		else if (ptr->val ==RR)
		printf("rr");
		else if (ptr->val ==RRA)
		printf("rra");
		else if (ptr->val ==RRB)
		printf("rrb");
		else if (ptr->val ==RRR)
		printf("rrr");
		printf("\n");
		ptr=ptr->next;
	}
		printf("\n");
}