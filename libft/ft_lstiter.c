/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:49:48 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 14:19:55 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst->next != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
	(*f)(lst->content);
}

// void ft_toz(void *element)
// {
// 	int		i;
// 	char	*content;

// 	i = 0;
// 	content = (char *)element;
// 	while (content[i])
// 		content[i++] = 'z';
// }

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *un;
// 	t_list *deux;
// 	t_list *trois;
// 	t_list *quatre;
// 	char	*d;
// 	char	*u;
// 	char	*q;
// 	char	*t;

// 	d = ft_strdup("deux");
// 	u = ft_strdup("un");
// 	q = ft_strdup("quatre");
// 	t = ft_strdup("trois");
// 	un = ft_lstnew(u);
// 	deux = ft_lstnew(d);
// 	trois = ft_lstnew(t);
// 	quatre = ft_lstnew(q);
// 	ft_lstadd_front(&un, deux);
// 	ft_lstadd_front(&deux, trois);
// 	ft_lstadd_front(&trois, quatre);

// 	ft_lstiter(quatre, &ft_toz);

// 	while (quatre->next != NULL)
// 	{
// 		printf("%s\n", (char *)quatre->content);
// 		quatre = quatre->next;
// 	}
// 	printf("%s\n", (char *)quatre->content);
// }