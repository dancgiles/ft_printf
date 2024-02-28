/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:51:30 by dcastro-          #+#    #+#             */
/*   Updated: 2024/02/28 20:02:32 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_count_unsigned(unsigned int n)
{
	size_t			count;

	count = 1;
	if (n <= 9)
		return (count);
	while (n / 10 > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_unsigned_itoa(unsigned int n)
{
	char			*res;
	unsigned int	n_value;
	unsigned int	char_n;
	size_t			size;

	size = ft_count_unsigned(n);
	res = malloc(size + 1);
	if (!res)
		return (0);
	res[size] = '\0';
	n_value = n;
	while (size)
	{
		char_n = n_value;
		while (char_n > 9)
			char_n = char_n % 10;
		res[--size] = char_n + 48;
		n_value = n_value / 10;
	}
	size = ft_putstr(res);
	free(res);
	return ((int)size);
}
