/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:46:33 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/09 19:14:47 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tiny_sort(t_stack **a)
{
	t_stack	*f;
	t_stack	*m;
	t_stack	*l;

	f = *a;
	m = (*a)->next;
	l = (*a)->next->next;
	if (m->num > f->num && m->num > l->num && f->num < l->num)
	{
		ft_rra(a, 1);
		ft_sa(a, 1);
	}
	else if (m->num < f->num && m->num < l->num && f->num < l->num)
		ft_sa(a, 1);
	else if (m->num > f->num && m->num > l->num && f->num > l->num)
		ft_rra(a, 1);
	else if (m->num < f->num && m->num < l->num && f->num > l->num)
		ft_ra(a, 1);
	else if (m->num < f->num && m->num > l->num)
	{
		ft_ra(a, 1);
		ft_sa(a, 1);
	}
}

void	ft_tiny_sort_b(t_stack **b)
{
	t_stack	*f;
	t_stack	*m;
	t_stack	*l;

	f = *b;
	m = (*b)->next;
	l = (*b)->next->next;
	if (m->num > f->num && m->num > l->num && f->num < l->num)
		ft_rb(b, 1);
	else if (m->num < f->num && m->num < l->num && f->num < l->num)
		ft_rrb(b, 1);
	else if (m->num > f->num && m->num > l->num && f->num > l->num)
		ft_sb(b, 1);
	else if (m->num < f->num && m->num < l->num && f->num > l->num)
	{
		ft_sb(b, 1);
		ft_rb(b, 1);
	}
	else if (m->num > f->num && m->num < l->num)
	{
		ft_rb(b, 1);
		ft_sb(b, 1);
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*b) == 1 && (*b)->num > (*a)->num)
	{
		ft_pb(a, b, 1);
		ft_sb(b, 1);
	}
	else if (ft_lstsize(*b) == 2)
	{
		ft_printf("Reached on tiny sort for b\n");
		ft_pb(a, b, 1);
		ft_tiny_sort_b(b);
	}
	else
	{
		ft_printf("Reached on rotate part\n");
		ft_rotate(a, b);
	}
}
