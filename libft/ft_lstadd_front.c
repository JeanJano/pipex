/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:34:44 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/18 17:44:00 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	*lst = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *list;
// 	t_list *new;

// 	new = ft_lstnew("piff");
// 	list = ft_lstnew("pouf");
// 	ft_lstadd_front(&list, new);
// 	while (new)
// 	{
// 		printf("%s\n", (char *)new->content);
// 		new = new->next;
// 	}
// }