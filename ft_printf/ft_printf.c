/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:05:01 by mzeouaou          #+#    #+#             */
/*   Updated: 2023/12/07 21:05:05 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	fonc_25line(int i, const char *str, va_list args, int *j)
{
	int	tmp;

	tmp = -1;
	if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		tmp = ft_putnbr(va_arg(args, int));
	else if (str[i] == '%' && str[i + 1] == 'c')
		tmp = ft_putchar(va_arg(args, int));
	else if (str[i] == '%' && str[i + 1] == 's')
		tmp = ft_putstr(va_arg(args, char *));
	else if (str[i] == '%' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		tmp = ft_putnbr_base(va_arg(args, int), str[i + 1]);
	else if (str[i] == '%' && str[i + 1] == 'p')
		tmp = ft_putp(va_arg(args, unsigned long));
	else if (str[i] == '%' && str[i + 1] == 'u')
		tmp = ft_putnbr_u(va_arg(args, unsigned int));
	else if (str[i] == '%' && str[i + 1] == '%')
		tmp = ft_putchar('%');
	else if (str[i] == '%' && str[i + 1] == '\0')
		return (-2);
	if (tmp >= 0)
	{
		*j += tmp;
		return (1);
	}
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;
	int		checker;

	if (str == NULL)
		return (-1);
	j = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		checker = -1;
		checker = fonc_25line(i, str, args, &j);
		if (checker == -2)
			return (-1);
		else if (checker == -1)
		{
			ft_putchar(str[i++]);
			j++;
		}
		else
			i += 2;
	}
	return (va_end(args), j);
}

// #include <stdio.h>
// int main()
// {
//     // int l;
//     // l = ft_printf("%p", &l);
//     // ft_printf("\nme : %d", l);
//     // l = ft_printf("mohamed %% ali %i %xuck %s the %corld\n%p",
//  12, 15, "all",'W', &l);
//     // printf("\nhe : %d", l);
// 	int i = ft_printf("%p", NULL);
// 	printf("%d", i);
// 	printf("\n--------------\n");
// 	int j =printf("%p", NULL);
// 	printf("%d", j);
//     return (0);
// }