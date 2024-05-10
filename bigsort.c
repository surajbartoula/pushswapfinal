/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:58:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/10 17:53:22 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	anticlockwise(t_stack **a, t_stack **b, int index)
{
	printf("index: %d\n", index);
	ft_rb(b, index);
	ft_pb(a, b, 1);
	ft_rrb(b, index);
}

void	clockwise(t_stack **a, t_stack **b, int index, int size)
{
	printf("index: %d\n", index);
	ft_rrb(b, size - index);
	ft_pb(a, b, 1);
	ft_rb(b, (size - index) + 1);
}

int	indexvalue(t_stack *lst, int num)
{
	if (lst == NULL || lst->next == NULL)
		return (0);
	if (num <= lst->num && num >= lst->next->num)
		return (1);
	return (0);
}

void	ft_rotate(t_stack **a, t_stack **b)
{
	t_stack	*cur;
	t_stack	*lst;
	int		index;

	if ((*a) == NULL)
		return ;
	else if ((*b) == NULL)
	{
		ft_pb(a, b, 1);
		return ;
	}
	fill_postion_index(b);
	cur = *b;
	while (cur->next != NULL)
		cur = cur->next;
	if ((*a)->num > (*b)->num)
		ft_pb(a, b, 1);
	else if ((*a)->num < cur->num)
	{
		ft_pb(a, b, 1);
		ft_rb(b, 1);
	}
	else
	{
		cur = *b;
		lst = *a;
		index = 0;
		while (cur != NULL && !(indexvalue(cur, lst->num)))
		{
			cur = cur->next;
			index++;
		}
		index++;
		printf("size: %d\n", ft_lstsize(*b));
		if (index <= (ft_lstsize(*b) - index))
			anticlockwise(a, b, index);
		else
			clockwise(a, b, index, ft_lstsize(*b));
	}
}
