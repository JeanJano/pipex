/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:36:07 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/19 09:45:29 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *un;
// 	t_list *deux;
// 	t_list *trois;
// 	t_list *quatre;

// 	un = ft_lstnew("un");
// 	deux = ft_lstnew("deux");
// 	ft_lstadd_front(&un, deux);
// 	trois = ft_lstnew("trois");
// 	ft_lstadd_front(&deux, trois);
// 	quatre = ft_lstnew(quatre);
// 	ft_lstadd_front(&trois, quatre);
// 	printf("i : %d", ft_lstsize(quatre));
// }