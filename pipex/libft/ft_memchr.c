/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:40 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/22 09:55:09 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}

// int main()
// {
// 	char str[] = ":(){ :|: & };:!";
// 	char *result1 = (char *)ft_memchr(str, '\xde', 15);
// 	if (result1)
// 	{
// 		printf("Test 1 - ft_memchr: '%c'
// encontrado en %p\n", 'W', (void *)result1);
// 	}
// 	else
// 	{
// 		printf("Test 1 - ft_memchr: '%c' no encontrado\n", 'W');
// 	}

// }

// int main()
// {
//     char str[] = "Hello, World!";
//     char *result1 = (char *)ft_memchr(str, '\0', sizeof(str));
//     if (result1)
//     {
//         printf("Test 1 - ft_memchr: '%c' encontrado en %p\n", 
//'W', (void *)result1);
//     }
//     else
//     {
//         printf("Test 1 - ft_memchr: '%c' no encontrado\n", 'W');
//     }
//     char *result2 = (char *)ft_memchr(str, 'z', sizeof(str));
//     if (result2)
//     {
//         printf("Test 2 - ft_memchr: '%c' 
//encontrado en %p\n", 'z', (void *)result2);
//     }
//     else
//     {
//         printf("Test 2 - ft_memchr: '%c' no encontrado\n", 'z');
//     }
//     char *result3 = (char *)ft_memchr(str, '\0', sizeof(str));
//     if (result3)
//     {
//         printf("Test 3 - ft_memchr: '\\0'
// encontrado en %p\n", (void *)result3);
//     }
//     else
//     {
//         printf("Test 3 - ft_memchr: '\\0' no encontrado\n");
//     }
//     return 0;
// }