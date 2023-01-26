/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:37:19 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/19 09:55:53 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>

// int	main()
// {
// 	t_list	*un;
// 	t_list	*deux;
// 	t_list	*trois;
// 	t_list	*getlast;

// 	un = ft_lstnew("un");
// 	deux = ft_lstnew("deux");
// 	ft_lstadd_front(&un, deux);
// 	trois = ft_lstnew("trois");
// 	ft_lstadd_front(&deux, trois);
// 	getlast = ft_lstlast(trois);
// 	printf("last : %s\n", (char *)getlast->content);
// }