/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:54:27 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/25 22:40:29 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	while (j > 0)
	{
		if (!*b)
			return ;
		tmp = *a;
		*a = *b;
		*b = (*b)->next;
		(*a)->next = tmp;
		ft_printf("pa\n");
		j--;
	}
}

void	ft_pb(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	while (j > 0)
	{
		if (!(*a))
			return ;
		tmp = *b;
		*b = *a;
		*a = (*b)->next;
		(*b)->next = tmp;
		ft_printf("pb\n");
		j--;
	}
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	while (j > 0)
	{
		ft_rra(a, 1);
		ft_rrb(b, 1);
		ft_printf("rrr\n");
		j--;
	}
}
