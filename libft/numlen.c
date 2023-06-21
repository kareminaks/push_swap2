/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:02:04 by kkaremin          #+#    #+#             */
/*   Updated: 2023/06/19 19:56:06 by kkaremin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(int num)
{
	int	res;

	if (num == -2147483648)
	{
		return (11);
	}
	if (num == 0)
	{
		return (1);
	}
	res = 0;
	if (num < 0)
	{
		res++;
		num *= -1;
	}
	while (num > 0)
	{
		res++;
		num /= 10;
	}
	return (res);
}

int	ft_putstr(char *c)
{
	ft_putstr_fd (c, 1);
	return (ft_strlen(c));
}

