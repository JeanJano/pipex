/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:29:14 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/16 12:35:11 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	i = -1;
	l = 0;
	while (dst[l])
		l++;
	while (src[++i] && (i + l + 1) < size)
		dst[l + i] = src[i];
	dst[l + i] = '\0';
	return (l + ft_strlen(src));
}

// #include <bsd/string.h>
// #include <stdio.h>
// // gcc -o test ft_strlcat.c -lbsd
// int	main(void)
// {
// 	char dst[50] = "lorem ipsum dolor sit amete";
// 	char buffer[] = "rrrr";

// 	printf("return (: %ld\n", ft_strlcat(buffer, dst, 2));
// 	printf("copy : %s", buffer);

// 	printf("\n\n");
// 	char dst1[50] = "lorem ipsum dolor sit amete";
// 	char buffer1[] = "rrrr";

// 	printf("return (: %ld\n", strlcat(buffer1, dst1, 2));
// 	printf("copy : %s", buffer1);
// 	return (0);
// }