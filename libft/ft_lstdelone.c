/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:45:53 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 14:20:17 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

// #include <stdio.h>

// void	ft_del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list *un;
// 	t_list *deux;
// 	t_list *trois;
// 	t_list *quatre;
// 	char *d;

// 	d = ft_strdup("deux");
// 	un = ft_lstnew("un");
// 	deux = ft_lstnew(d);
// 	trois = ft_lstnew("trois");
// 	quatre = ft_lstnew("quatre");
// 	ft_lstadd_front(&un, deux);
// 	ft_lstadd_front(&deux, trois);
// 	ft_lstadd_front(&trois, quatre);

// 	ft_lstdelone(deux, &ft_del);
// 	// printf("%s\n", (char *)deux->content);
// 	while (trois->next != NULL){
// 		printf("%s\n", (char *)trois->content);
// 		trois = trois->next;
// 	}
// 	printf("%s\n", (char *)trois->content);
// }