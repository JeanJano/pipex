/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:03:35 by jsauvage          #+#    #+#             */
/*   Updated: 2022/11/13 13:05:01 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_pipex
{
	int		fd_infile;
	int		fd_outfile;
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	char	*path;
	char	*access;
	int		status;
}			t_pipex;

void		ft_init(char **av, t_pipex *pipex);

void		ft_free(t_pipex *pipex);
void		ft_free_split(char **arr);
char		*ft_newstrjoin(char *s1, char *s2);

void		ft_check_access(char *path, char **cmd, t_pipex *pipex);
void		ft_check_file(t_pipex *pipex, char *file, char **s_cmd, int fd[2]);
void		ft_parsing(char **envp, t_pipex *pipex);

int			ft_error_pid(int pid, int fd[2]);
void		ft_error_return(t_pipex *pipex, int pid1, int pid2);
int			ft_error_arg(int ac);

#endif