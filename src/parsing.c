/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:27:59 by jsauvage          #+#    #+#             */
/*   Updated: 2022/11/13 14:02:08 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_null_access(t_pipex *pipex, char **cmd, char **split_path)
{
	if (pipex->access == NULL)
	{
		ft_free_split(cmd);
		free(split_path);
		ft_free(pipex);
		exit(127);
	}
}

static int	ft_abs_path(t_pipex *pipex, char *cmd)
{
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
		{
			pipex->access = ft_strdup(cmd);
			return (0);
		}
		if (access(cmd, X_OK) == -1)
			exit(126);
	}
	return (1);
}

void	ft_check_access(char *path, char **cmd, t_pipex *pipex)
{
	char	**split_path;
	int		i;
	char	*res;
	int		accss;

	if (ft_abs_path(pipex, cmd[0]) == 0)
		return ;
	split_path = ft_split(path, ':');
	i = 0;
	pipex->access = NULL;
	while (split_path[i])
	{
		res = ft_newstrjoin(split_path[i], "/");
		res = ft_newstrjoin(res, cmd[0]);
		accss = access(res, X_OK);
		if (accss == 0)
			pipex->access = ft_strdup(res);
		free(res);
		i++;
	}
	ft_null_access(pipex, cmd, split_path);
}

void	ft_check_file(t_pipex *pipex, char *file, char **s_cmd, int fd[2])
{
	if (access(file, F_OK) == 0 && access(file, R_OK) != 0)
	{
		ft_free_split(s_cmd);
		close(fd[0]);
		close(fd[1]);
		ft_free(pipex);
		exit(1);
	}
	else
	{
		ft_free_split(s_cmd);
		close(fd[0]);
		close(fd[1]);
		ft_free(pipex);
		exit(126);
	}
}

void	ft_parsing(char **envp, t_pipex *pipex)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T'
				&& envp[i][3] == 'H' && envp[i][4] == '=')
		{
			pipex->path = ft_strdup(ft_strchr(envp[i], '/'));
			break ;
		}
		i++;
	}
	if (pipex->path == NULL)
	{
		free(pipex->cmd1);
		free(pipex->cmd2);
		free(pipex->infile);
		free(pipex->outfile);
		free(pipex);
		exit(0);
	}
}
