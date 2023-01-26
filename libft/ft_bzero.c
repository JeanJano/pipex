/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:58:32 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/11 13:42:17 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(char *) s++ = 0;
}
/*
#include <stdio.h>
#include <unistd.h>
int     main()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";

	printf("avant : %s", str);

	ft_bzero(str + 13, 4 * sizeof(char));
	printf("\napres : %s", str);
}*/
