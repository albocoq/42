/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:12:55 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/12 09:42:49 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
