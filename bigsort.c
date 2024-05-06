/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:58:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/05 21:19:28 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	anticlockwise(t_stack **a, t_stack **b, int index)
{
	ft_ra(a, index - 1);
	ft_pb(a, b, 1);
}

void	clockwise(t_stack **a, t_stack **b, int index, int size)
{
	ft_rra(a, (size - index) + 1);
	ft_pb(a, b, 1);
}

void	ft_rotate_push(t_stack **a, t_stack **b, int len)
{
	int		i;
	int		index;
	int		size;
	t_stack	*current;

	i = 1;
	while (i < len - 2)
	{
		index = 1;
		current = *a;
		size = ft_lstsize(current);
		while (current && current->p_index != i)
		{
			current = current->next;
			index++;
		}
		if (index <= (size - index))
			anticlockwise(a, b, index);
		else
			clockwise(a, b, index, size);
		i++;
	}
}

void	ft_bigsort(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_lstsize(*a);
	ft_divideconquer(a, b, len);
	ft_rotate_push(a, b, len);
	if (ft_lstsize(*a) == 3)
		ft_tiny_sort(a);
	ft_pa(a, b, len - 3);
}
