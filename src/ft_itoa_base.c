/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:50:48 by dcastro-          #+#    #+#             */
/*   Updated: 2024/02/28 20:04:17 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	to_hex(int num, char c)
{
	if (num >= 10)
	{
		if (c == 'l')
			return (num - 10 + 'a');
		else
			return (num - 10 + 'A');
	}
	else
		return (num + '0');
}

int	ft_itoa_base(unsigned long n, unsigned int base, char c)
{
	char			*res;
	int				i;
	unsigned long	num;

	i = 0;
	num = n;
	while (num >= base)
	{
		num = num / base;
		i++;
	}
	res = malloc(i + 2);
	if (!res)
		return (0);
	res[i + 1] = '\0';
	while (i >= 0)
	{
		num = n % base;
		res[i] = to_hex(num, c);
		n = n / base;
		i--;
	}
	i = ft_putstr(res);
	free(res);
	return (i);
}
