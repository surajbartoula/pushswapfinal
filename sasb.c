/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sasb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:27:55 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/07 20:47:58 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int j)
{
	t_stack	*tmp;

	while (j > 0)
	{
		if ((*a) == NULL || (*a)->next == NULL)
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
		if (*b == NULL || (*b)->next == NULL)
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
		if (*a == NULL || (*a)->next == NULL || (*b) == NULL
			|| (*b)->next == NULL)
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
