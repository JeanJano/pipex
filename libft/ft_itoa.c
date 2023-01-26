/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:54:42 by jsauvage          #+#    #+#             */
/*   Updated: 2022/07/12 14:03:59 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_revstr(char *s)
{
	int		i;
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

char	*ft_itoa(int n)
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

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char *str;
// 	str = ft_itoa(INT_MIN);
// 	printf("%s", str);
// 	free(str);
// 	// printf("%d", ft_itoa(0)[1]);
// }