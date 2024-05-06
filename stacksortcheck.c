/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacksortcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:19:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/25 22:51:52 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(int *arr, int len)
{
	int	i;

	if (len == 1)
		exit(0);
	i = -1;
	while (++i < (len - 1))
	{
		if (arr[i] > arr[i + 1])
			return (0);
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if ((size_t)start >= slen)
	{
		str = malloc(1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > slen - start)
		len = slen - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
