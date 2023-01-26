/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:30:37 by jsauvage          #+#    #+#             */
/*   Updated: 2022/07/12 14:57:34 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
		i++;
	return (i);
}

static int	checkstring(char *base)
{
	int	i;
	int	j;
	int	boolean;

	boolean = 1;
	i = 0;
	while (base[i] != 0)
	{
		j = 0;
		while (base[j] != 0)
		{
			if (base[i] == base[j] && i != j)
			{
				boolean = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	return (boolean);
}

static int	checkcondition(char *base)
{
	int	boolean;
	int	i;

	boolean = 1;
	if (count(base) < 2)
		boolean = 0;
	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '-' || base[i] == '+')
		{
			boolean = 0;
			break ;
		}
		i++;
	}
	if (checkstring(base) == 0)
		boolean = 0;
	return (boolean);
}

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	long	a;
	int		size;
	int		check;

	size = count(base);
	a = nbr;
	check = checkcondition(base);
	if (check == 1)
	{
		if (a < 0)
		{
			write(1, "-", 1);
			a = -1 * a;
		}
		if (a > size - 1)
			ft_putnbr_base((a / size), base);
		ft_putchar(base[a % size]);
	}
}
