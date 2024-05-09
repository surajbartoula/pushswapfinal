/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:11:44 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/09 18:10:47 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *stack, const char *name) {
    if (stack == NULL) {
        printf("%s is empty\n", name);
        return;
    }

    printf("Contents of stack %s:\n", name);
    while (stack != NULL) {
        printf("%d -> ", stack->num);
        stack = stack->next;
    }
    printf("NULL\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	returnlsta(argc, argv, &a);
	size = ft_lstsize(a);
	if (!a || duplicate(a))
	{
		ft_free_stack(&a);
		ft_error("Duplicate number or stack doesn't exist.");
	}
	else if (size == 1 || (size == 2 && (a->num < a->next->num)))
	{
		ft_free_stack(&a);
		return (0);
	}
	else if (size == 2 && (a->num > a->next->num))
		ft_sa(&a, 1);
	else if (size == 3)
		ft_tiny_sort(&a);
	else
	{
		fill_postion_index(&a);
		while (ft_lstsize(a) > 3)
		{
			ft_divideconquer(&a, &b, ft_lstsize(a));
			ft_printf("Got out of the divideconquer.\n");
			print_stack(a, "a");
			print_stack(b, "b");

			// if (ft_lstsize(b) > 0)
			// 	fill_postion_index(&b);
			// if (ft_lstsize(a) > 0)
			// 	fill_postion_index(&a);
		}
		ft_printf("AFTER WHILE LOOP\n");
		size = ft_lstsize(a);
		if (size == 2 && (a->num > a->next->num))
			ft_sa(&a, 1);
		else if (size == 3)
			ft_tiny_sort(&a);
		ft_pa(&a, &b, ft_lstsize(b));
	}
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
