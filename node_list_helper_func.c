/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_list_helper_func.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:15:45 by kkaremin          #+#    #+#             */
/*   Updated: 2023/06/21 17:23:19 by kkaremin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node_t	*new_node(int value)
{
	node_t	*head;

	head = (node_t *)malloc(sizeof(node_t));
	if (!head)
		return (0);
	head->val = value;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

//creates new list
list_t	new_list(void)
{
	list_t res;

	res.head = 0;
	res.tail = 0;
	return (res);
}

void	rra_n(list_t *list_a, int length, int n, list_t *command_list)
{
	int	i;

	i = 0;
	if (n > length / 2)
	{
		while (i < length - n)
		{
			ra(list_a, 1, command_list);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			rra(list_a, 1, command_list);
			i++;
		}
	}
}

void	rrb_n(list_t *list_b, int length, int n, list_t *command_list)
{
	int	i;

	i = 0;
	if (n > length / 2)
	{
		while (i < length - n)
		{
			rb(list_b, 1, command_list);
			i++;
		}
	}
}
