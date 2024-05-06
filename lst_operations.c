/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:18:36 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/26 05:46:41 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new_lst)
{
	t_stack	*node;

	if (*lst)
	{
		node = *lst;
		while (node->next)
			node = node->next;
		node->next = new_lst;
	}
	else
		*lst = new_lst;
}

t_stack	*ft_lstnew(int num)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->next = NULL;
	node->num = num;
	return (node);
}

void	ft_free_stack(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		(*lst)->num = 0;
		(*lst)->p_index = 0;
		free(*lst);
		*lst = temp;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
