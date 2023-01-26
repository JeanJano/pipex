/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:21:58 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/22 09:42:31 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (d > s)
		while (n--)
			d[n] = s[n];
	else
	{
		while (n--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[100] = "Geeksfor";
// 	ft_memmove(str + 5, str, strlen(str) + 1);
// 	printf("test: %s\n", str);
// 	char str1[100] = "Geeksfor";
// 	memmove(str1 + 5, str1, strlen(str1) + 1);
// 	printf("base: %s\n", str1);
// }
