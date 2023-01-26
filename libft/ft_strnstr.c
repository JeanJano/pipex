/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:19:46 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 15:18:58 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;
	int		i;

	l = len;
	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (*big && len)
	{
		if (*big == *little && !ft_strncmp(big, little, ft_strlen(little)) && (i
				+ ft_strlen(little) - 1) < l)
			return ((char *)big);
		big++;
		len--;
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <bsd/string.h>
// // gcc -o test ft_strnstr.c -lbsd

// int	main(void)
// {
// 	const char *big = "aaabcabcd";
// 	const char *little = "a";
// 	char *ptr;

// 	ptr = strnstr(big, little, 1);
// 	printf("\nbase : %s\n", ptr);

// 	const char *big1 = "aaabcabcd";
// 	const char *little1 = "a";
// 	char *ptr1;

// 	ptr1 = ft_strnstr(big1, little1, 1);
// 	printf("test : %s\n\n", ptr1);
// }