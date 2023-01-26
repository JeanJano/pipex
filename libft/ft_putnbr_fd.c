/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:09:41 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 15:16:54 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	a;

	a = n;
	if (a < 0)
	{
		write(fd, "-", 1);
		a = -1 * a;
	}
	if (a > 9)
	{
		ft_putnbr_fd(a / 10, fd);
	}
	ft_putchar_fd('0' + (a % 10), fd);
}

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND | O_TRUNC, 0644);
// 	if (fd == -1)
// 		printf("error");
// 	ft_putnbr_fd(-666, fd);
// 	close(fd);
// }