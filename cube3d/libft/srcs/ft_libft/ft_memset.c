/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:21:12 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/11 13:13:37 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
