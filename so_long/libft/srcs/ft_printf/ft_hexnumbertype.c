/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnumbertype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:02:36 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/10 10:09:16 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexnumbertype(va_list args, char a, int base)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	if (a == 'X')
		return (ft_putbase(nb, base, 1));
	return (ft_putbase(nb, base, 0));
}
