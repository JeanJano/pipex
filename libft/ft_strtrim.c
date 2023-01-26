/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:54:29 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 15:20:23 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	checksep(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_strlen(char const *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

static int	ft_count(int l, int i)
{
	if (l == 0)
		return (0);
	else
		return (l - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		l;
	int		x;

	i = -1;
	while (s1[++i])
		if (!checksep(s1[i], set))
			break ;
	l = ft_strlen(s1);
	if (checksep(s1[l - 1], set))
	{
		while (s1[--l - 1])
			if (!checksep(s1[l - 1], set))
				break ;
	}
	res = malloc((ft_count(l, i) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	x = 0;
	while (i < l)
		res[x++] = s1[i++];
	return (res[x] = 0, res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_strtrim("   xxx   xxx", " x"));
// }