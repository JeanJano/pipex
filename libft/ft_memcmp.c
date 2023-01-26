/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:30:46 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/05 15:45:13 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n)
	{
		if (*(unsigned char *)s1 < *(unsigned char *)s2)
			return (-1);
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (1);
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
// 	int arr[] = {1, 910, -7, 8};
// 	int arr1[] = {1, 910, 7, 10};
// 	printf("\nbase : %d\n", memcmp(arr, arr1, 3 * sizeof(int)));
// 	printf("test : %d\n\n", ft_memcmp(arr, arr1, 3 * sizeof(int)));

// 	printf("\nbase : %d\n", memcmp("arr9", "arr5", 4 * sizeof(char)));
// 	printf("test : %d\n\n", ft_memcmp("arr9", "arr5", 4 * sizeof(char)));
// }