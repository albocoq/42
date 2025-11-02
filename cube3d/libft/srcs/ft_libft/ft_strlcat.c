/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:28:24 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/10 10:02:18 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	count2;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	count2 = ft_strlen(src);
	if (dst_len >= size)
		return (size + count2);
	count = dst_len;
	while (count < size - 1 && *src)
	{
		dst[count] = *src;
		count++;
		src++;
	}
	dst[count] = '\0';
	return (dst_len + count2);
}
