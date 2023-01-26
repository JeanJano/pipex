/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:30:12 by jsauvage          #+#    #+#             */
/*   Updated: 2022/07/12 15:05:21 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(const char *s, int counter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && (s[i + 1] == 's' || s[i + 1] == 'c' || s[i
					+ 1] == 'd' || s[i + 1] == 'p' || s[i + 1] == 'i' || s[i
					+ 1] == 'u' || s[i + 1] == 'x' || s[i + 1] == 'X' || s[i
					+ 1] == '%'))
		{
			count += 2;
			i++;
		}
		i++;
	}
	return (count - counter);
}

void	ft_while(int i, const char *s, int *count, va_list vl)
{
	while (i < ft_strlen_printf(s))
	{
		if (s[i] == '%' && s[i + 1] == '%')
			ft_putpercent(count, &i, s);
		if (s[i] == '%' && s[i + 1] == 's')
			ft_putstr(va_arg(vl, char *), count, &i);
		else if (s[i] == '%' && s[i + 1] == 'c')
			ft_putc(va_arg(vl, int), &i, count);
		else if (s[i] == '%' && s[i + 1] == 'p')
			ft_print_memory(va_arg(vl, unsigned long), &i, count);
		else if (s[i] == '%' && s[i + 1] == 'd')
			ft_putnbr(va_arg(vl, int), count, &i);
		else if (s[i] == '%' && s[i + 1] == 'i')
			ft_putnbr(va_arg(vl, int), count, &i);
		else if (s[i] == '%' && s[i + 1] == 'u')
			ft_putunnbr(va_arg(vl, unsigned int), count, &i);
		else if (s[i] == '%' && s[i + 1] == 'x')
			ft_puthex(va_arg(vl, unsigned int), "0123456789abcdef", count, &i);
		else if (s[i] == '%' && s[i + 1] == 'X')
			ft_puthex(va_arg(vl, unsigned int), "0123456789ABCDEF", count, &i);
		else
			write(1, &s[i++], 1);
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	vl;

	va_start(vl, s);
	i = 0;
	count = 0;
	ft_while(i, s, &count, vl);
	va_end(vl);
	return (ft_strlen_printf(s) - ft_count(s, count));
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int c;
// 	int a;

// 	a = ft_printf("%s");
// 	printf("\n");
// 	c = printf("%s", "0123546\0789");
// 	printf("\n");
// 	printf("\nlongueur de ma fonction : %d", a);
// 	printf("\nlongueur de la fonction de base : %d", c);
// 	return (0);
// }