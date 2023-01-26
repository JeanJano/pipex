/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:15:49 by jsauvage          #+#    #+#             */
/*   Updated: 2022/11/13 13:04:58 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init(char **av, t_pipex *pipex)
{
	pipex->fd_infile = open(av[1], O_RDONLY);
	pipex->infile = ft_strdup(av[1]);
	pipex->cmd1 = ft_strdup(av[2]);
	pipex->cmd2 = ft_strdup(av[3]);
	pipex->outfile = ft_strdup(av[4]);
	pipex->fd_outfile = open(av[4], O_CREAT | O_TRUNC | O_RDWR, 0666);
	pipex->access = NULL;
	pipex->path = NULL;
}
