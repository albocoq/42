/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:12:55 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/22 09:55:09 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			count;

	count = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (count < n)
	{
		if (c1[count] != c2[count])
			return ((unsigned char)c1[count] - (unsigned char)c2[count]);
		count++;
	}
	return (0);
}

// int main()
// {
//     char str1[] = "Hola";
//     char str2[] = "Hola";
//     int result1 = ft_memcmp(str1, str2, 4);
//     printf("Test 1 - ft_memcmp: %d\n", result1);
//     char str3[] = "Hola";
//     char str4[] = "Mundo";
//     int result2 = ft_memcmp(str3, str4, 4);
//     printf("Test 2 - ft_memcmp: %d\n", result2);
//     char str5[] = "A";
//     char str6[] = "B";
//     int result3 = ft_memcmp(str5, str6, 1);
//     printf("Test 3 - ft_memcmp: %d\n", result3);
//     return 0;
// }