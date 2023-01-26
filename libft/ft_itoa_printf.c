/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:50:36 by jsauvage          #+#    #+#             */
/*   Updated: 2022/07/12 14:55:01 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	countchar(long n)
{
	long	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_revstr(char *s)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < ft_strlen(s) / 2)
	{
		tmp = s[i];
		s[i] = s[ft_strlen(s) - i - 1];
		s[ft_strlen(s) - i - 1] = tmp;
		i++;
	}
	return (s);
}

static int	chechnegative(long n, int *negative)
{
	*negative = 0;
	if (n < 0)
	{
		*negative = 1;
		n *= -1;
	}
	return (n);
}

char	*ft_itoa_printf(long n)
{
	char			*res;
	int				i;
	int				negative;
	unsigned int	nb;

	res = malloc((countchar(n) + 1) * sizeof(char));
	nb = n;
	if (!res)
		return (NULL);
	nb = chechnegative(n, &negative);
	i = 0;
	while (nb || i == 0)
	{
		res[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	if (negative)
	{
		res[i] = '-';
		res[i + 1] = 0;
	}
	else
		res[i] = 0;
	return (ft_revstr(res));
}
