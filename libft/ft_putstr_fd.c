/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:26:01 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/10 12:46:44 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <sys/stat.h>
// #include <sys/types.h>

// int	main(void)
// {
// 	int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 		printf("error");
// 	char str[] = "str";
// 	ft_putstr_fd(str, fd);
// 	close(fd);
// }