/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:02:18 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/11 16:27:34 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	n1;

	n1 = n;
	while (n--)
		*(unsigned char *)s++ = c;
	return (s - n1);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str1[50] = "GeeksForGeeks is for programming geeks.";
// 	printf("base :\n");
// 	printf("avant : %s", str1);
// 	printf("\nreturn: %p", memset(str1 + 13, '^', 4));
// 	printf("\napres : %s", str1);

// 	char str[50] = "GeeksForGeeks is for programming geeks.";
// 	printf("\n\n\ntest :\n");
// 	printf("avant : %s", str);
// 	printf("\nreturn (: %p", ft_memset(str + 13, '^', 4)));
// 	printf("\napres : %s", str);
// }