/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:26:49 by jsauvage          #+#    #+#             */
/*   Updated: 2022/09/01 12:56:36 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	signe;

	i = 0;
	signe = 1;
	while (ft_isspace(nptr[i]))
		i++;
	result = 0;
	if (nptr[i] == '-' && nptr[i + 1] != '+')
	{
		signe = -1;
		i++;
	}
	if (nptr[i] == '+')
		i++;
	i--;
	while (nptr[++i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i] - '0';
	return (result * signe);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	printf("\nbase: %d", atoi(" \t\n\v\f\r -+48"));
// 	printf("\ntest: %d\n\n", ft_atoi(" \t\n\v\f\r -+48"));
// }