/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:58:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/09 19:53:49 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	anticlockwise(t_stack **a, t_stack **b, int index)
{
	ft_rb(b, index - 1);
	ft_pb(a, b, 1);
	ft_rrb(b, index - 1);
}

void	clockwise(t_stack **a, t_stack **b, int index, int size)
{
	ft_rrb(b, (size - index) + 2);
	ft_pb(a, b, 1);
	ft_rb(b, (size + 2 - index) + 1);
}

int	indexvalue(t_stack *lst, int num)
{
	if (lst == NULL || lst->next == NULL)
		return (0);
	if (num >= lst->num && num <= lst->next->num)
		return (1);
	return (0);
}

void	ft_rotate(t_stack **a, t_stack **b)
{
	t_stack	*cur;
	t_stack	*lst;
	int		index;

	if ((*a) == NULL)
	{
		ft_printf("The value is null.\n");
		return ;
	}
	else if ((*b) == NULL)
	{
		ft_pb(a, b, 1);
		return ;
	}
	fill_postion_index(b);
	cur = *b;
	while (cur->next != NULL)
		cur = cur->next;
	ft_printf("cur.num is %d\n", cur->num);
	ft_printf("b.num first is %d\n", (*b)->num);
	ft_printf("a.num is %d\n", (*a)->num);
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
		index = 1;
		ft_printf("The a.num is %d\n", lst->num);
		ft_printf("The value of cur.num is %d\n", cur->num);
		while (cur != NULL && (indexvalue(cur, lst->num)) != 1)
		{
			index++;
			cur = cur->next;
		}
		ft_printf("The index value is: %d\n", index);
		if (index <= (ft_lstsize(*b) - index))
			anticlockwise(a, b, index);
		else
			clockwise(a, b, index, ft_lstsize(*b));
	}
}
