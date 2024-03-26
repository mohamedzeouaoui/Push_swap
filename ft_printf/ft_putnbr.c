/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:43:23 by mzeouaou          #+#    #+#             */
/*   Updated: 2023/12/09 10:43:29 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <stdio.h>

int	count(long nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb *= -1;
		i = i + 1;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	i = i + 1;
	return (i);
}

void	ft_put(long nb)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
		return ;
	}
	else if (nb > 9)
	{
		ft_put(nb / 10);
		ft_putchar(48 + nb % 10);
	}
}

int	ft_putnbr(int nb)
{
	int	cmp;

	cmp = count(nb);
	ft_put(nb);
	return (cmp);
}

// int main()
// {
//     int n;
//     int l;

//     printf("\n%d", ft_putnbr(-2147483648));
//     return (0);
// }