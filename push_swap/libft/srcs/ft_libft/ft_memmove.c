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

#include "libft.h"

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

// int main()
// {
// 	char dest_str[] = '\0'; 
// 	char src_str[] = '\0';

// 	puts("source string [src_str] before memmove:-"); 
// 	puts(dest_str); 

// 	memmove(dest_str, src_str, 5); 

// 	puts("\nsource string [src_str] after memmove:-"); 
// 	puts(dest_str); 
// }