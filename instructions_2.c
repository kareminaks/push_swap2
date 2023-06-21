/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:35:40 by kkaremin          #+#    #+#             */
/*   Updated: 2023/06/21 17:38:46 by kkaremin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_head(list_t *list, node_t *node)
{
	if (list->head == 0)
	{
		list->head = node;
		list->tail = node;
		node->prev = 0;
		node->next = 0;
	}
	else
	{
		list->head->prev = node;
		node->next = list->head;
		list->head = node;
		node->prev = 0;
	}
}

void	push_tail(list_t *list, node_t *node)
{
	if (list->tail == 0)
	{
		list->head = node;
		list->tail = node;
		node->prev = 0;
		node->next = 0;
	}
	else
	{
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
		node->next = 0;
	}
}
//pa (push a): Take the first element at
//the top of b and put it at the top of a.
//Do nothing if b is empty.

void	pa(list_t *list_a, list_t *list_b, int print, list_t *command_list)
{
	node_t	*head;

	if (print)
		put_command_in_list(PA, command_list);
	head = pop_head(list_b);
	if (!head)
		return ;
	push_head(list_a, head);
}

//pb (push b): Take the first element at
//the top of a and put it at the top of b.
//Do nothing if a is empty.

void	pb(list_t *list_b, list_t *list_a, int print, list_t *command_list)
{
	node_t	*head;

	if (print)
		put_command_in_list(PB, command_list);
	head = pop_head(list_a);
	if (!head)
		return ;
	push_head(list_b, head);
}
