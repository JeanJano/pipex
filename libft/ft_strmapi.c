/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:59:39 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 15:18:21 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s1;

	s1 = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s1[i] = (*f)(i, s[i]);
		i++;
	}
	s1[i] = 0;
	return (s1);
}

// char rotone(unsigned int i, char c)
// {
// 	return (c + 1);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_strmapi("test", &rotone));
// }