/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:06:47 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/22 09:55:09 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cur;
	char	*dst_data;
	char	*src_data;

	if (!src && !dst)
		return (NULL);
	cur = 0;
	dst_data = (char *)dst;
	src_data = (char *)src;
	while (cur < n)
	{
		dst_data[cur] = src_data[cur];
		cur++;
	}
	return (dst_data);
}

// int main()
// {
//     char src[] = "Hola Mundo!";
//     char dst[20]; 

//     ft_memcpy(dst, src, 12);
//     printf("Test 1 - ft_memcpy: %s\n", dst);

//     char src2[] = "123456789";
//     char dst2[5];

//     ft_memcpy(dst2, src2, 4);
//     dst2[4] = '\0';
//     printf("Test 2 - ft_memcpy: %s\n", dst2);

//     char src3[] = "";
//     char dst3[1];

//     ft_memcpy(dst3, src3, 1);
//     printf("Test 3 - ft_memcpy: '%s'\n", dst3); 

//     return 0;
// }