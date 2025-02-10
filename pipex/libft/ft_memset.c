/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:21:12 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/22 09:55:09 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_memset(void *str, int a, size_t num)
{
	unsigned char	*ptr;

	ptr = str;
	while (num--)
	{
		*ptr = (unsigned char)a;
		ptr++;
	}
	return (str);
}

// int main()
// {
//     char str1[20] = "Hola Mundo!";
//     ft_memset(str1, '*', 5);
//     printf("Test 1 - ft_memset: %s\n", str1);
//     char str2[10] = "ABCDEFGH";
//     ft_memset(str2, 0, 3);
//     printf("Test 2 - ft_memset: %s\n", str2);
//     char str3[5] = "1234";
//     ft_memset(str3, '#', 4);
//     printf("Test 3 - ft_memset: %s\n", str3);
//     return 0;
// }