/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointertype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:23:00 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/10 10:09:10 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointertype(va_list args, int base)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)va_arg(args, void *);
	if ((char *)ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
		write(1, "0x", 2);
	return (2 + ft_putbase(ptr, base, 0));
}
