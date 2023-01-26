/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:28:49 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 15:17:39 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		count;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = -1;
	count = 0;
	while (s1[++i])
		res[count++] = s1[i];
	i = -1;
	while (s2[++i])
		res[count++] = s2[i];
	res[count] = 0;
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_strjoin("piff", "pouf"));
// }