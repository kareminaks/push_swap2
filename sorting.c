/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:22:25 by kkaremin          #+#    #+#             */
/*   Updated: 2023/06/21 17:18:18 by kkaremin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortlist_a(list_t *list_a, list_t *list_b, int depth,
		list_t *command_list)
{
	int	n;
	int	length;

	if (depth < 3)
	{
		smallsort_a(list_a, depth, command_list);
		return ;
	}
	n = push_small_tob(list_a, list_b, depth, command_list);
	length = get_list_length(list_a);
	rra_n(list_a, length, depth - n, command_list);
	sortlist_a(list_a, list_b, depth - n, command_list);
	sortlist_b(list_b, list_a, n, command_list);
	pa_n(list_a, list_b, n, command_list);
}

void	sortlist_b(list_t *list_b, list_t *list_a, int depth,
		list_t *command_list)
{
	int	median;
	int	n;
	int	length;

	if (depth < 3)
	{
		smallsort_b(list_b, depth, command_list);
		return ;
	}
	median = get_median(list_b, depth);
	n = push_big_toa(list_b, list_a, depth, command_list);
	length = get_list_length(list_b);
	rrb_n(list_b, length, depth - n, command_list);
	sortlist_a(list_a, list_b, n, command_list);
	sortlist_b(list_b, list_a, depth - n, command_list);
	pb_n(list_b, list_a, n, command_list);
}

int	get_median(list_t *list, int depth)
{
	long long	sum;
	int			i;
	node_t		*ptr;

	sum = 0;
	i = 0;
	ptr = list->head;
	while (i < depth)
	{
		sum += ptr->val;
		ptr = ptr->next;
		i++;
	}
	return (sum / (long long)depth);
}

int	push_big_toa(list_t *list_b, list_t *list_a, int depth,
		list_t *command_list)
{
	int	moved;
	int	i;
	int	median;

	median = get_median(list_a, depth);
	moved = 0;
	i = 0;
	while (i < depth)
	{
		if (list_b->head->val > median)
		{
			pa(list_a, list_b, 1, command_list);
			moved++;
		}
		else
		{
			rb(list_b, 1, command_list);
		}
		i++;
	}
	return (moved);
}

int	push_small_tob(list_t *list_a, list_t *list_b, int depth,
		list_t *command_list)
{
	int		moved;
	int		i;
	int		median;
	node_t	*ptr;

	median = get_median(list_a, depth);
	moved = 0;
	i = 0;
	ptr = list_a->head;
	while (i < depth)
	{
		ptr = list_a->head;
		if (ptr->val <= median)
		{
			pb(list_b, list_a, 1, command_list);
			moved++;
		}
		else
		{
			ra(list_a, 1, command_list);
		}
		i++;
	}
	return (moved);
}
