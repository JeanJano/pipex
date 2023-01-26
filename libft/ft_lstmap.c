/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:50:20 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 14:19:40 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	res = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			(*del)(tmp);
			free(tmp);
		}
		if (!res)
			res = tmp;
		else
			ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}

// void	ft_del(void *content)
// {
// 	free(content);
// }

// void    *ft_map(void *ct)
// {
//     int i;
//     void *c;
//     char *pouet;

//     c = ct;
// 	i = -1;
// 	pouet = (char *)c;
// 	while (pouet[++i])
// 		if (pouet[i] == 'o')
// 			pouet[i] = 'a';
//     return (c);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *un;
// 	t_list *deux;
// 	t_list *trois;
// 	t_list *quatre;
//     t_list *list;
// 	char	*d;
// 	char	*u;
// 	char	*q;
// 	char	*t;

// 	d = ft_strdup("oooooo");
// 	u = ft_strdup("ooo");
// 	q = ft_strdup("ooooo");
// 	t = ft_strdup("oo");
// 	un = ft_lstnew(u);
// 	deux = ft_lstnew(d);
// 	trois = ft_lstnew(t);
// 	quatre = ft_lstnew(q);
// 	ft_lstadd_front(&un, deux);
// 	ft_lstadd_front(&deux, trois);
// 	ft_lstadd_front(&trois, quatre);

// 	list = ft_lstmap(quatre, &ft_map, &ft_del);

// 	while (list->next != NULL)
// 	{
// 		printf("%s\n", (char *)list->content);
// 		list = list->next;
// 	}
// }