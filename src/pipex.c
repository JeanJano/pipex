/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:48:17 by jsauvage          #+#    #+#             */
/*   Updated: 2022/11/13 13:04:47 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_exec1(t_pipex *pipex, int fd[2], char **envp)
{
	char	**cmd_split;

	cmd_split = ft_split(pipex->cmd1, ' ');
	if (pipex->fd_infile == -1)
		ft_check_file(pipex, pipex->infile, cmd_split, fd);
	ft_check_access(pipex->path, cmd_split, pipex);
	dup2(pipex->fd_infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(pipex->access, cmd_split, envp);
	return (1);
}

static int	ft_exec2(t_pipex *pipex, int fd[2], char **envp)
{
	char	**cmd_split;

	cmd_split = ft_split(pipex->cmd2, ' ');
	if (pipex->fd_outfile == -1)
		ft_check_file(pipex, pipex->outfile, cmd_split, fd);
	ft_check_access(pipex->path, cmd_split, pipex);
	dup2(pipex->fd_outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(pipex->access, cmd_split, envp);
	return (1);
}

static int	ft_pipe(t_pipex *pipex, char **envp)
{
	int		fd[2];
	int		pid1;
	int		pid2;

	if (pipe(fd) == -1)
		return (0);
	pid1 = fork();
	if (ft_error_pid(pid1, fd) == 0)
		return (0);
	if (pid1 == 0)
		ft_exec1(pipex, fd, envp);
	pid2 = fork();
	if (ft_error_pid(pid2, fd) == 0)
		return (0);
	if (pid2 == 0)
		ft_exec2(pipex, fd, envp);
	close(fd[0]);
	close(fd[1]);
	ft_error_return(pipex, pid1, pid2);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		status;

	if (ft_error_arg(ac) != 5)
		return (1);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	ft_init(av, pipex);
	ft_parsing(envp, pipex);
	if (ft_pipe(pipex, envp) == 0)
		return (1);
	status = WEXITSTATUS(pipex->status);
	ft_free(pipex);
	return (status);
}
