/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:50:49 by kkaremin          #+#    #+#             */
/*   Updated: 2023/06/21 19:48:42 by kkaremin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort_3(list_t *list_a, list_t *command_list)
{
	int	a;
	int	b;
	int	c;

	a = list_a->head->val;
	b = list_a->head->next->val;
	c = list_a->tail->val;
	if ((a < b) && (b > c) && (a < c))
	{
		sa(list_a, 1, command_list);
		ra(list_a, 1, command_list);
	}
	else if ((a > b) && (b < c) && (a < c))
		sa(list_a, 1, command_list);
	else if ((a < b) && (b > c) && (a > c))
		rra(list_a, 1, command_list);
	else if ((a > b) && (b < c) && (a > c))
		ra(list_a, 1, command_list);
	else if ((a > b) && (b > c) && (a > c))
	{
		ra(list_a, 1, command_list);
		sa(list_a, 1, command_list);
	}
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int	true_median(list_t *list_a)
{
	int		len;
	int		*arr;
	node_t	*list;
	int		i;
	int		median;

	len = get_list_length(list_a);
	arr = calloc(len, sizeof(int));
	list = list_a->head;
	i = 0;
	while (list)
	{
		arr[i++] = list->val;
		list = list->next;
	}
	bubble_sort(arr, len);
	median = arr[len / 2];
	free(arr);
	return (median);
}

void	small_sort_5(list_t *list_a, list_t *list_b, list_t *command_list)
{
	int	i;
	int	depth;
	int	median;
	int	moved;

	i = 0;
	depth = 5;
	median = true_median(list_a);
	while (i < depth)
	{
		if (list_a->head->val < median)
			pb(list_b, list_a, 1, command_list);
		else
			ra(list_a, 1, command_list);
		i++;
	}
	moved = depth / 2;
	small_sort_3(list_a, command_list);
	smallsort_b(list_b, 2, command_list);
	pa_n(list_a, list_b, 2, command_list);
}
