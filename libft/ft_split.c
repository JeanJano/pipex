/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:57:02 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/21 15:21:58 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	countword(char const *s, char c)
{
	int	i;
	int	count;

	if (!s[0])
		return (0);
	if (c == 0)
		return (1);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i + 1] == c && s[i] != c)
			count++;
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static int	countletter(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	freesplit(int j, char **res)
{
	while (j >= 0)
	{
		free(res[j]);
		j--;
	}
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		tabi[3];

	tabi[0] = 0;
	tabi[1] = -1;
	res = malloc((countword(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (++tabi[1] < countword(s, c) && s[0])
	{
		tabi[2] = 0;
		while (s[tabi[0]] == c)
			tabi[0]++;
		res[tabi[1]] = malloc((countletter(s + tabi[0], c) + 1) * sizeof(char));
		if (!res[tabi[1]])
		{
			freesplit(tabi[1], res);
			return (NULL);
		}
		while (s[tabi[0]] != c && s[tabi[0]] != '\0')
			res[tabi[1]][tabi[2]++] = s[tabi[0]++];
		res[tabi[1]][tabi[2]] = '\0';
	}
	res[tabi[1]] = 0;
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int i;

// 	i = 0;
// 	// ft_split(" salut    c'est     un test ", ' ');
// 	char **test = ft_split("tripouille" , 0);
// 	while (test[i])
// 	{
// 		printf("%d : %s\n", i, test[i]);
// 		i++;
// 	}
// 	printf("%s", test[1]);
// 	// if (!test[0])
// 	// 	printf("ok\n");
// 	i = 0;
// 	while (test[i])
// 	{
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// }