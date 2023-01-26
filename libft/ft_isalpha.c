/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:57:53 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/11 14:31:19 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
// 	printf("\nbase : %d\n", isalpha('Z'));
// 	printf("test : %d\n\n", ft_isalpha('A'));
// }
