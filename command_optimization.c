#include "push_swap.h"

//command dictionary
// sa : 1
// sb : 2
// ss : 3
// pa : 4
// pb : 5
// ra : 6
// rb : 7
// rr : 8
// rra : 9
// rrb : 10
// rrr : 11

void	put_command_in_list(int command, list_t *command_list)
{
	node_t	*nod;

	nod = new_node(command);
	nod->prev = command_list->tail;
	command_list->tail->next = nod;
	command_list->tail = nod;
}

int	check_command_cancel(int a, int b)
{
	if (((a == PA) && (b == PB)) ||
		((a == PB) && (b == PA)) ||
		((a == RA) && (b == RRA)) ||
		((a == RRA) && (b == RA)) ||
		((a == RB) && (b == RRB)) ||
		((a == RRB) && (b == RB)) ||
		((a == RRR) && (b == RR)) ||
		((a == RR) && (b == RRR)) ||
		((a == SA) && (b == SA)) ||
		((a == SB) && (b == SB)))
		return (1);
	else
		return (0);
}

int	check_command_replace(int a, int b)
{
	if (((a == SA) && (b == SB)) ||
		((a == SB) && (b == SA)))
		return (SS);
	else if (((a == RA) && (b == RB)) ||
				((a == RB) && (b == RA)))
		return (RR);
	else if (((a == RRA) && (b == RRB)) ||
				((a == RRB) && (b == RRA)))
		return (RRR);
	else
		return (0);
}

void	optimize_commands(list_t *command_list, list_t *optimized_list)
{
	node_t	*head;
	node_t	*node;

	optimized_list->head = pop_head(command_list);
	optimized_list->tail = optimized_list->head;
	while (command_list->head != 0)
	{
		if (check_command_cancel(command_list->head->val,
				optimized_list->tail->val) == 1)
		{
			free(pop_tail(optimized_list));
			free(pop_head(command_list));
		}
		else if (check_command_replace(command_list->head->val,
					optimized_list->tail->val) != 0)
		{
			head = pop_head(command_list);
			optimized_list->tail->val = check_command_replace(head->val,
					optimized_list->tail->val);
			free(head);
		}
		else
		{
			node = pop_head(command_list);
			push_tail(optimized_list, node);
		}
	}
}
