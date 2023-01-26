/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:43:23 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/17 14:28:21 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// #include <string.h>
// int	main(void)
// {
// 	char data[] = {0, 1, 2 ,3 ,4 ,5};
// 	char *pos = memchr(data, 2 + 256, 3);
// 	printf("\nbase : pos[0] = %d | pos[1] = %d\n", pos[0], pos[1]);

// 	char data1[] = {0, 1, 2 ,3 ,4 ,5};
// 	char *pos1 = ft_memchr(data1, 2 + 256, 3);
// 	printf("test : pos[0] = %d | pos[1] = %d\n\n", pos1[0], pos1[1]);
// }