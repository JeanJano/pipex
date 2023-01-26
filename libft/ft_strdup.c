/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:59:52 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 15:17:20 by jsauvage         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = malloc(ft_strlen(s) + 1);
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = 0;
	return (dup);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char *dup;

// 	dup = strdup("test");
// 	printf("\nbase: %s\n", dup);

// 	char *dup1;

// 	dup1 = ft_strdup("test");
// 	printf("test: %s|\n\n", dup1);
// }