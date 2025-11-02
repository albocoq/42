/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:51:33 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/10 10:02:29 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	while (src[count] && count < size - 1 && size)
	{
		dest[count] = src[count];
		count++;
	}
	if (size)
		dest[count] = 0;
	return (ft_strlen(src));
}
