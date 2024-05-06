/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:27:21 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/25 22:47:41 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				neg;
	long long int	i;

	i = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error("Not all the provided arguments contains numbers.");
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((neg * i) > 2147483647 || (neg * i) < -2147483648)
		ft_error("The provided arguments exceeds int value.");
	return (neg * i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tdest;
	unsigned char	*tsrc;

	if (dest == NULL && src == NULL)
		return (0);
	tdest = (unsigned char *)dest;
	tsrc = (unsigned char *)src;
	while (n > 0)
	{
		*tdest = *tsrc;
		tdest++;
		tsrc++;
		n--;
	}
	return (dest);
}
