/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:59:42 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 15:20:45 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_count(const char *s, unsigned int start, size_t len)
{
	int	count;

	if (start > ft_strlen(s) - 1)
		return (0);
	if (len > ft_strlen(s))
		return (ft_strlen(s));
	count = 0;
	while (start < ft_strlen(s) && len)
	{
		count++;
		start++;
		len--;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_count(s, start, len);
	res = malloc((count + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < count)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

// int	main(void)
// {
// 	char str[] = "BONJOUR LES HARICOTS !";
// 	char *s = ft_substr("tripouille", 100, 1);
// 	printf("%s", s);
// 	free(s);
// }