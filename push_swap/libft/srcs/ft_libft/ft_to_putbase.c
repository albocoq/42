/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_putbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:43:49 by aboussem          #+#    #+#             */
/*   Updated: 2025/03/03 12:19:59 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_to_putbase(uintptr_t nb, int base)
{
	int	result;
	int	multiplier;

	if (base < 2 || base > 10)
		return (-1);

	result = 0;
	multiplier = 1;
	while (nb > 0)
	{
		result += (nb % base) * multiplier;
		nb /= base;
		multiplier *= 10;
	}
	return (result);
}
