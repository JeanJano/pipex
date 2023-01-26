/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:01:29 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 15:18:43 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	dif(char s1, char s2)
{
	if (s1 < 0)
		return (s2 - s1);
	if (s2 < 0)
		return (s2 - s1);
	return (s1 - s2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (s1[0] == 0 || s2[0] == 0)
		return (*s1 - *s2);
	while (s1 && s2 && n)
	{
		if (*s1 != *s2)
			return (dif(*s1, *s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	printf("base: %d\n", strncmp("test\0", "test\200", 6));
// 	printf("test: %d", ft_strncmp("test\0", "test\200", 6));
// }