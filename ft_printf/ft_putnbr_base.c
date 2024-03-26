/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:48:55 by mzeouaou          #+#    #+#             */
/*   Updated: 2023/12/10 14:48:59 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <stdio.h>

int	cont(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb < 16)
		return (1);
	else
	{
		while (nb > 15)
		{
			nb = nb / 16;
			i++;
		}
	}
	i = i + 1;
	return (i);
}

void	ft_put_base(unsigned int nb, char bs)
{
	char	*base;

	if (bs == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb < 16)
	{
		ft_putchar(base[nb]);
	}
	else
	{
		ft_put_base(nb / 16, bs);
		ft_putchar(base[nb % 16]);
	}
}

int	ft_putnbr_base(unsigned int nb, char bs)
{
	int	a;

	a = cont(nb);
	ft_put_base(nb, bs);
	return (a);
}

// int main()
// {
//     int a = ft_putnbr_base(0, 'X');
//     ft_putchar('\n');
//     ft_putnbr(a);
//     return (0);
// }