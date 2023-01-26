/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:28:30 by jsauvage          #+#    #+#             */
/*   Updated: 2022/07/14 20:08:54 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	countchar(unsigned long n)
{
	long	i;

	i = 1;
	while (n > 15)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static char	*ft_revstr(char *s)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < ft_strlen_printf(s) / 2)
	{
		tmp = s[i];
		s[i] = s[ft_strlen_printf(s) - i - 1];
		s[ft_strlen_printf(s) - i - 1] = tmp;
		i++;
	}
	return (s);
}

char	*ft_itohex(unsigned long n, char *base)
{
	char			*res;
	int				i;

	res = malloc((countchar(n) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (n || i == 0)
	{
		res[i] = base[n % 16];
		n /= 16;
		i++;
	}
	res[i] = '\0';
	return (ft_revstr(res));
}

void	ft_puthex(unsigned long n, char *base, int *count, int *i)
{
	int		j;
	char	*str;

	j = 0;
	str = ft_itohex(n, base);
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	*count += ft_strlen_printf(str);
	*i += 2;
	free(str);
}

// #include <stdio.h>

// int	main()
// {
// 	char *str;

// 	str = ft_itohex(29, "0123456789abcdef");
// 	printf("%s\n", str);
// 	free(str);
// }