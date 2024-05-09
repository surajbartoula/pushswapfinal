/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:54:27 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/08 19:48:19 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	while (j > 0 && *b != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
		ft_printf("pa\n");
		j--;
	}
}

void	ft_pb(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if ((*a) == NULL)
		return ;
	while (j > 0 && *a != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
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
