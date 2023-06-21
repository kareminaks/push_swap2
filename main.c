/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:22:48 by kkaremin          #+#    #+#             */
/*   Updated: 2023/06/21 17:31:53 by kkaremin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(list_t *list)
{
	node_t	*ptr;
	node_t	*next;

	ptr = list->head;
	while (ptr)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
}

int	main(int argc, char **argv)
{
	list_t	list_a;
	list_t	list_b;
	list_t	command_list;
	list_t	optimized_list;

	check_input(argc, argv);
	list_a = new_list();
	list_b = new_list();
	command_list = new_list();
	command_list.head = new_node(0);
	command_list.tail = command_list.head;
	optimized_list = new_list();
	fill_list_a(argc, argv, &list_a);
	choose_algo(&list_a, &list_b, &command_list);
	optimize_commands(&command_list, &optimized_list);
	print_list(&optimized_list);
	free_list(&list_a);
	free_list(&list_b);
	free_list(&optimized_list);
}

void	choose_algo(list_t *list_a, list_t *list_b, list_t *command_list)
{
	int	l;

	l = get_list_length;
	if (list_is_sorted(list_a))
		return ;
	if (l == 3)
		small_sort_3(list_a, command_list);
	else if (l == 5)
		small_sort_5(list_a, list_b, command_list);
	else
		sortlist_a(&list_a, &list_b, l, &command_list);
}

void	print_instruction(int instruction)
{
	if (instruction == SA)
		ft_printf("sa");
	else if (instruction == SB)
		ft_printf("sb");
	else if (instruction == SS)
		ft_printf("ss");
	else if (instruction == PA)
		ft_printf("pa");
	else if (instruction == PB)
		ft_printf("pb");
	else if (instruction == RA)
		ft_printf("ra");
	else if (instruction == RB)
		ft_printf("rb");
	else if (instruction == RR)
		ft_printf("rr");
	else if (instruction == RRA)
		ft_printf("rra");
	else if (instruction == RRB)
		ft_printf("rrb");
	else if (instruction == RRR)
		ft_printf("rrr");
	ft_printf("\n");
}

void	print_list(list_t *list)
{
	node_t	*ptr;

	if (list->head == 0)
		return ;
	ptr = list->head;
	while (ptr != 0)
	{
		print_instruction(ptr->val);
		ptr = ptr->next;
	}
}

int	list_is_sorted(list_t *list_a)
{
	node_t *ptr = list_a->head;
	if (!ptr || !ptr->next)
		return (1);

	int prev = ptr->val;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->val < prev)
			return (0);
		prev = ptr->val;
		ptr = ptr->next;
	}
	return (1);
}