/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divideconquer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:55:40 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/10 05:17:46 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	medianvalue(t_stack *lst, int len)
{
	t_stack	*cur;
	int		i;
	int		median;

	if (!lst)
		return (0);
	cur = lst;
	i = 0;
	median = 0;
	while (i < len)
	{
		median += cur->p_index;
		cur = cur->next;
		i++;
	}
	ft_printf("Med value: %d\n", median);
	ft_printf("len value: %d\n", len);
	ft_printf("Median value: %d\n", median / len);
	return (median / len);
}

void	ft_divideconquer(t_stack **a, t_stack **b, int len)
{
	int		median;
	int		i;

	median = medianvalue(*a, len);
	if (median == 0)
		return ;
	i = 0;
	while (i < len)
	{
		if ((*a)->p_index <= median)
			ft_sort(a, b);
		else
			ft_ra(a, 1);
		i++;
	}
}
