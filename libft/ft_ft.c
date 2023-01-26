/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:35:20 by jsauvage          #+#    #+#             */
/*   Updated: 2022/07/12 14:25:33 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_memory(unsigned long pointer, int *i, int *count)
{
	char	*str;

	if (pointer == 0)
	{
		write(1, "(nil)", 5);
		*count += 5;
		*i += 2;
	}
	else
	{
		write(1, "0x", 2);
		str = ft_itohex(pointer, "0123456789abcdef");
		ft_putstr(str, count, i);
		*count += 2;
		free(str);
	}
}

void	ft_putnbr(int n, int *count, int *i)
{
	long	a;
	char	*str;
	int		j;

	a = n;
	j = 0;
	str = ft_itoa(a);
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	*i += 2;
	*count += ft_strlen(str);
	free(str);
}

void	ft_putstr(char *str, int *count, int *nb)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		*count += 6;
	}
	else
	{
		i = 0;
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		*count += i;
	}
	*nb += 2;
}

void	ft_putunnbr(unsigned int n, int *count, int *i)
{
	char	*str;
	int		j;

	j = 0;
	str = ft_itoa(n);
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	*i += 2;
	*count += ft_strlen(str);
	free(str);
}
