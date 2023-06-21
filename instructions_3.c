/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:39:14 by kkaremin          #+#    #+#             */
/*   Updated: 2023/06/21 17:40:01 by kkaremin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(list_t *list_a, int print, list_t *command_list)
{
	node_t	*head;

	if (print)
		put_command_in_list(RA, command_list);
	head = pop_head(list_a);
	if (!head)
		return ;
	push_tail(list_a, head);
}


void	rb(list_t *list_b, int print, list_t *command_list)
{
	node_t	*head;

	if (print)
		put_command_in_list(RB, command_list);
	head = pop_head(list_b);
	if (!head)
		return ;
	push_tail(list_b, head);
}

void	rr(list_t *list_a, list_t *list_b, int print, list_t *command_list)
{
	if (print)
		put_command_in_list(RR, command_list);
	ra(list_a, 0, command_list);
	rb(list_b, 0, command_list);
}

void	rra(list_t *list_a, int print, list_t *command_list)
{
	node_t	*tail;

	if (print)
		put_command_in_list(RRA, command_list);
	tail = pop_tail(list_a);
	if (!tail)
		return ;
	push_head(list_a, tail);
}

void	rrb(list_t *list_b, int print, list_t *command_list)
{
	node_t	*tail;

	if (print)
		put_command_in_list(RRB, command_list);
	tail = pop_tail(list_b);
	if (!tail)
		return ;
	push_head(list_b, tail);
}
//rrr : rra and rrb at the same time
void	rrr(list_t *list_a, list_t *list_b, int print, list_t *command_list)
{
	if (print)
		put_command_in_list(RRR, command_list);
	rra(list_a, 0, command_list);
	rrb(list_b, 0, command_list);
}
