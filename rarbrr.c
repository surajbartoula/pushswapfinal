/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarbrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:56:00 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/27 15:01:54 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a, int j)
{
	t_stack	*tmp;

	while (j > 0)
	{
		if (!*a || !(*a)->next)
			return ;
		tmp = *a;
		*a = ft_lstlast(*a);
		(*a)->next = tmp;
		*a = tmp->next;
		tmp->next = NULL;
		ft_printf("ra\n");
		j--;
	}
}

void	ft_rb(t_stack **b, int j)
{
	t_stack	*tmp;

	while (j > 0)
	{
		if (!*b || !(*b)->next)
			return ;
		tmp = *b;
		*b = ft_lstlast(*b);
		(*b)->next = tmp;
		*b = tmp->next;
		tmp->next = NULL;
		ft_printf("rb\n");
		j--;
	}
}

void	ft_rr(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	while (j > 0)
	{
		if (!*a || !((*a)->next) || !*b || !((*b)->next))
			return ;
		tmp = *a;
		*a = ft_lstlast(*a);
		(*a)->next = tmp;
		*a = tmp->next;
		tmp->next = NULL;
		tmp = *b;
		*b = ft_lstlast(*b);
		(*b)->next = tmp;
		*b = tmp->next;
		tmp->next = NULL;
		ft_printf("rr\n");
		j--;
	}
}

void	ft_rra(t_stack **a, int j)
{
	t_stack	*tmp;
	int		i;

	while (j > 0)
	{
		if (!*a || !(*a)->next)
			return ;
		i = 0;
		tmp = *a;
		while ((*a)->next)
		{
			*a = (*a)->next;
			i++;
		}
		(*a)->next = tmp;
		while (i > 1)
		{
			tmp = tmp->next;
			i--;
		}
		tmp->next = NULL;
		ft_printf("rra\n");
		j--;
	}
}

void	ft_rrb(t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	while (j > 0)
	{
		if (!*b || !(*b)->next)
			return ;
		i = 0;
		tmp = *b;
		while ((*b)->next)
		{
			i++;
			*b = (*b)->next;
		}
		(*b)->next = tmp;
		while (i > 1)
		{
			tmp = tmp->next;
			i--;
		}
		tmp->next = NULL;
		ft_printf("rrb\n");
		j--;
	}
}
