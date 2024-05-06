/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:36:28 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/27 11:12:06 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_printf("Error: %s\n", str);
	exit(0);
}

void	ft_free(char **argv)
{
	char	*str;
	int		i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i] != 0)
	{
		str = argv[i];
		i++;
		free(str);
	}
	free(argv);
}

int	duplicate(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->num == temp->num)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}
