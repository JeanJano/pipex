/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:16:42 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/18 16:59:36 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *test;

// 	test = ft_lstnew("merci romeo");
// 	test->next = ft_lstnew("encore merci romeo");
// 	printf("%s\n", (char *)test->content);
// 	test = test->next;
// 	printf("%s", (char *)test->content);
// }