/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:57:36 by jsauvage          #+#    #+#             */
/*   Updated: 2022/11/16 14:18:32 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize_char(t_list_char *lst)
{
	int			count;
	t_list_char	*head;

	count = 0;
	head = lst;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

t_list_char	*ft_lstnew_char(char content)
{
	t_list_char	*result;

	result = malloc(sizeof(t_list_char));
	if (!result)
		return (0);
	result->content = content;
	result->next = NULL;
	return (result);
}

t_list_char	*ft_lstlast_char(t_list_char *lst)
{
	t_list_char	*head;

	if (lst == NULL)
		return (0);
	head = lst;
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_lstadd_back_char(t_list_char **lst, t_list_char *new)
{
	t_list_char	*last;

	if (*lst)
	{
		last = ft_lstlast_char(*lst);
		last->next = new;
	}
	else
		*lst = new;
}
