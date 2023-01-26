/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:45:20 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 14:39:33 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast((*lst));
		last->next = new;
	}
	else
		*lst = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*un;
// 	t_list	*deux;
// 	t_list	*trois;
// 	t_list	*getlast;
// 	t_list	*end;

// 	un = ft_lstnew("un");
// 	deux = ft_lstnew("deux");
// 	trois = ft_lstnew("trois");
// 	end = ft_lstnew("end");
// 	ft_lstadd_front(&un, deux);
// 	ft_lstadd_front(&deux, trois);
// 	ft_lstadd_back(&trois, end);
// 	getlast = ft_lstlast(trois);
// 	printf("last : %s\n", (char *)getlast->content);
// }