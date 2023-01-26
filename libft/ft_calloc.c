/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:01:43 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/18 11:01:31 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;
	size_t	c;

	if (nmemb == 0 || size == 0)
		return (tab = malloc(1), tab[0] = 0, tab);
	c = nmemb * size;
	if (c / nmemb != size)
		return (0);
	i = 0;
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	while (i < nmemb * size)
		tab[i++] = 0;
	return (tab);
}

// #include <stdio.h>
// #include <stdint.h>

// int	main(void)
// {
// 	int	i;
// 	i = -1;
// 	char *tab1 = (char *)ft_calloc(0, 0);
// 	// tab1[0] = 'a';
// 	printf("test : %p\n", tab1);
// 	while (++i < 10)
// 		printf("%d\n", tab1[i]);
// 	printf("\n");
// 	i = -1;
// 	char *tab = (char *)calloc(0, 0);
// 	printf("base : %p\n", tab);
// 	while (++i < 10)
// 		printf("%d\n", tab[i]);
// }