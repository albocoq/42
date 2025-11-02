/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:45:52 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/11 10:14:10 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	s = src;
	d = dest;
	if (s < d)
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
