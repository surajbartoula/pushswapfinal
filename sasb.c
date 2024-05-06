/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sasb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:27:55 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/25 05:37:38 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int j)
{
	t_stack	*tmp;

	while (j > 0)
	{
		if (!(*a) || !(*a)->next)
			return ;
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
		ft_printf("sa\n");
		j--;
	}
}

void	ft_sb(t_stack **b, int j)
{
	t_stack	*tmp;

	while (j > 0)
	{
		if (!(*b) || (*b)->next)
			return ;
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
		ft_printf("sb\n");
		j--;
	}
}

void	ft_ss(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	while (j > 0)
	{
		if (!(*a) || !((*a)->next) || !(*b) || ((*b)->next))
			return ;
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
		ft_printf("ss\n");
		j--;
	}
}
