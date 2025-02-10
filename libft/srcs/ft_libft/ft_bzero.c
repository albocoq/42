/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:43:47 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/11 13:22:13 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p = 0;
		p++;
	}
}

// int main()
// {
//     char test1[10] = "123456789";
//     size_t len1 = 5;
//     printf("Avant ft_bzero :\n");
//     printf("Test 1: \"%s\"\n", test1);
//     ft_bzero(test1, len1);
//     printf("\nAprès ft_bzero :\n");
//     printf("Test 1: \"%s\", Premier num: %c\n", test1, test1[5]);
//     char test3[10] = "123456789";
//     printf("\nAvant bzero (libc) sur test2 :\n");
//     printf("Test 1: \"%s\"\n", test3);
//     bzero(test3, 5);
//     printf("\nAprès bzero (libc) sur test2 :\n");
//     printf("Test 1: \"%s\", Premier num: %c\n", test3, test3[5]);
//     return 0;
// }