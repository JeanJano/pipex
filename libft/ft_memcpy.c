/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:14:08 by jsauvage          #+#    #+#             */
/*   Updated: 2022/05/22 09:40:39 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	size;

	if (!dest && !src)
		return (NULL);
	size = n;
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (dest - size);
}

/* 
#include <stdio.h>
int	main()
{
	int array [] = { 54, 85, 20, 63, 21 };
	int * copy = NULL;
	int length = sizeof( int ) * 5;

	// Memory allocation and copy 
	copy = (int *) malloc( length );
	ft_memcpy( copy, array, length );

	// Display the copied values 
	for( length=0; length<5; length++ ) {
		printf( "%d ", copy[ length ] );
	}
	printf( "\n" );

	free( copy );
} */
