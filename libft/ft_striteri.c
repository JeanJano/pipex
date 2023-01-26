/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:39:04 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/09 17:35:38 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = -1;
	while (s[++i])
		(*f)(i, s + i);
}

// void	rotone(unsigned int i, char *s)
// {
// 	*s += 1;
// }

// int	main(void)
// {
// 	char str[] = "oui";
// 	ft_striteri(str, &rotone);
// 	printf("%s", str);
// }