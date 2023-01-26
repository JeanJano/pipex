/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:47:37 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/19 12:59:36 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = tmp;
	}
	lst = NULL;
}

// void	ft_del(void *content)
// {
// 	free(content);
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
// 	ft_lstadd_back(&un, deux);
// 	ft_lstadd_back(&un, trois);
// 	ft_lstadd_back(&un, quatre);

// 	ft_lstclear(&deux, &ft_del);
// 	while (un)
// 	{
// 		printf("%s\n", un->next ? (char *)un->content : NULL);
// 		un = un->next;
// 	}
// }