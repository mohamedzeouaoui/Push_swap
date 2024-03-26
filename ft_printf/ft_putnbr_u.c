/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:26:10 by mzeouaou          #+#    #+#             */
/*   Updated: 2023/12/10 18:26:16 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <stdio.h>

int	counte(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	i = i + 1;
	return (i);
}

void	ft_put_u(unsigned int nb)
{
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
		return ;
	}
	else if (nb > 9)
	{
		ft_put_u(nb / 10);
		ft_putchar(48 + nb % 10);
	}
}

int	ft_putnbr_u(unsigned int nb)
{
	unsigned int	cmp;

	cmp = counte(nb);
	ft_put_u(nb);
	return (cmp);
}
