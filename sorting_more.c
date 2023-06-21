/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:18:29 by kkaremin          #+#    #+#             */
/*   Updated: 2023/06/21 17:26:06 by kkaremin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	smallsort_a(list_t * list_a, int depth, list_t *command_list)
{
	if (depth < 2)
		return ;
	if (list_a->head->val < list_a->head->next->val)
		return ;
	sa(list_a, 1, command_list);
}

void	smallsort_b(list_t *list_b, int depth, list_t *command_list)
{
	if (depth < 2)
		return ;
	if (list_b->head->val > list_b->head->next->val)
		return ;
	sb(list_b, 1, command_list);
}

void	pa_n(list_t *list_a, list_t *list_b, int n, list_t *command_list)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pa(list_a, list_b, 1, command_list);
		i++;
	}
}

void	pb_n(list_t *list_b, list_t *list_a, int n, list_t *command_list)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pb(list_b, list_a, 1, command_list);
		i++;
	}
}

int	get_list_length(list_t *list)
{
	int l = 0;
	node_t *ptr = list->head;
	while (ptr != 0)
	{
		l++;
		ptr = ptr->next;
	}
	return (l);
}