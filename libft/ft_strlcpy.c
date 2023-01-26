/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:17:30 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 15:18:02 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	if (size == 0)
		return (ft_strlen(src));
	n = ft_strlen(src);
	i = -1;
	while (++i < size - 1 && n--)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <bsd/string.h>
// // gcc -o test ft_strlcpy.c -lbsd
// int	main(void)
// {
// 	char str1[27] = "lorem ipsum dolor sit amet";
// 	char buffer1[27];

// 	printf("base : return (: %ld\n", strlcpy(buffer1, str1, 0));
// 	printf("copy : %d", buffer1[0]);

// 	printf("\n\n");
// 	char str[27] = "lorem ipsum dolor sit amet";
// 	char buffer[27];

// 	printf("test : return (: %ld\n", ft_strlcpy(buffer, str, 0));
// 	printf("copy : %d", buffer[0]);
// 	return (0);
// }