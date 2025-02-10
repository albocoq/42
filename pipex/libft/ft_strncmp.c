/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:10:21 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/22 09:55:09 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (s1[count] != s2[count])
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		if (s1[count] == '\0')
			break ;
		count++;
	}
	return (0);
}

// int main()
// {
//     char str1[] = "Hola Mundo";
//     char str2[] = "Hola Mundo";
//     int result1 = ft_strncmp(str1, str2, 10);
//     printf("Test 1 - ft_strncmp: %d\n", result1);
//     char str3[] = "Hola Mundo";
//     char str4[] = "Hola Mundo!";
//     int result2 = ft_strncmp(str3, str4, 10);
//     printf("Test 2 - ft_strncmp: %d\n", result2);
//     char str5[] = "Hola Mundo!";
//     char str6[] = "Hola Mundo!!!";
//     int result3 = ft_strncmp(str5, str6, 12);
//     printf("Test 3 - ft_strncmp: %d\n", result3);
//     char str7[] = "Hola";
//     char str8[] = "Hola Mundo";
//     int result4 = ft_strncmp(str7, str8, 5);
//     printf("Test 4 - ft_strncmp: %d\n", result4);
//     return 0;
// }