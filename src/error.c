/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:41:17 by jsauvage          #+#    #+#             */
/*   Updated: 2022/11/13 13:16:27 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_arg(int ac)
{
	char	*nb_ac;

	if (ac != 5)
	{
		nb_ac = ft_itoa(ac - 1);
		ft_putstr_fd("vous avez rentre ", 2);
		ft_putstr_fd(nb_ac, 2);
		ft_putstr_fd(" argument. il en faut 4", 2);
		free(nb_ac);
	}
	return (ac);
}

int	ft_error_pid(int pid, int fd[2])
{
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (0);
	}
	return (1);
}

static void	ft_print_error(char *message, char *error)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
}

static void	ft_exit_error(t_pipex *pipex, int cmd, int fd, char *name)
{
	char	**error;

	if (cmd == 1)
		error = ft_split(pipex->cmd1, ' ');
	else if (cmd == 2)
		error = ft_split(pipex->cmd2, ' ');
	if (WEXITSTATUS(pipex->status) == 1 && fd == -1)
		ft_print_error("permission denied", name);
	else if (WEXITSTATUS(pipex->status) == 126 && access(error[0], X_OK) == -1)
		ft_print_error("permission denied", error[0]);
	else if (WEXITSTATUS(pipex->status) == 126)
		ft_print_error("no such file or directory", pipex->infile);
	else if (WEXITSTATUS(pipex->status) == 127 && access(error[0], X_OK) == -1)
		ft_print_error("command not found", error[0]);
	ft_free_split(error);
}

void	ft_error_return(t_pipex *pipex, int pid1, int pid2)
{
	waitpid(pid1, &pipex->status, 0);
	if (WEXITSTATUS(pipex->status) != 0)
		ft_exit_error(pipex, 1, pipex->fd_infile, pipex->infile);
	waitpid(pid2, &pipex->status, 0);
	if (WEXITSTATUS(pipex->status) != 0)
		ft_exit_error(pipex, 2, pipex->fd_outfile, pipex->outfile);
}
