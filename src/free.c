/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:29:02 by jsauvage          #+#    #+#             */
/*   Updated: 2022/11/07 16:23:04 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(t_pipex *pipex)
{
	free(pipex->cmd1);
	free(pipex->cmd2);
	free(pipex->path);
	free(pipex->infile);
	free(pipex->outfile);
	free(pipex);
}

void	ft_free_split(char **arr)
{
	int	count;
	int	i;

	count = 0;
	while (arr[count])
		count++;
	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*ft_newstrjoin(char *s1, char *s2)
{
	char	*newstr;

	newstr = ft_strjoin(s1, s2);
	free(s1);
	return (newstr);
}
