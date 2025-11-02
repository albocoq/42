/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:10:21 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/11 13:11:27 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
