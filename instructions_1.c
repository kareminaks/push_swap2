/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:20:13 by kkaremin          #+#    #+#             */
/*   Updated: 2023/06/21 17:34:48 by kkaremin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(list_t *list_a, int print, list_t *command_list)
{
	node_t	*top;
	node_t	*prev;

	if (print)
		put_command_in_list(SA, command_list);
	if ((list_a->head == list_a->tail) || (!list_a->head))
	{
		return ;
	}
	top = pop_head(list_a);
	prev = pop_head(list_a);
	push_head(list_a, top);
	push_head(list_a, prev);
}
//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.

void	sb(list_t *list_b, int print, list_t *command_list)
{
	node_t	*top;
	node_t	*prev;

	if (print)
		put_command_in_list(SB, command_list);
	if ((list_b->head == list_b->tail) || (!list_b->head))
		return ;
	top = pop_head(list_b);
	prev = pop_head(list_b);
	push_head(list_b, top);
	push_head(list_b, prev);
}

//ss : sa and sb at the same time.
void	ss(list_t *list_a, list_t *list_b, int print, list_t *command_list)
{
	if (print)
		put_command_in_list(SS, command_list);
	sa(list_a, 0, command_list);
	sb(list_b, 0, command_list);
}

node_t	*pop_head(list_t *list)
{
	node_t	*node;

	if (!list->head)
	{
		return (0);
	}
	node = list->head;
	if (list->head == list->tail)
	{
		list->head = 0;
		list->tail = 0;
	}
	else
	{
		list->head = node->next;
		list->head->prev = 0;
	}
	node->prev = 0;
	node->next = 0;
	return (node);
}

node_t	*pop_tail(list_t *list)
{
	node_t	*node;

	if (!list->tail)
	{
		return (0);
	}
	node = list->tail;
	if (list->head == list->tail)
	{
		list->head = 0;
		list->tail = 0;
	}
	else
	{
		list->tail = node->prev;
		list->tail->next = 0;
	}
	node->prev = 0;
	node->next = 0;
	return (node);
}

