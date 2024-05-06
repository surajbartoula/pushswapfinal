/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:11:44 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/29 14:51:48 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = NULL;
	returnlsta(argc, argv, &a);
	if (!a || duplicate(a))
	{
		ft_free_stack(&a);
		ft_error("Duplicate number or stack doesn't exist.");
	}
	else if (ft_lstsize(a) == 1)
	{
		ft_free_stack(&a);
		return (0);
	}
	fill_postion_index(&a);
	ft_sort(&a);
	ft_free_stack(&a);
	return (0);
}
