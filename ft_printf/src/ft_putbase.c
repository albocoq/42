/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:43:49 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/18 13:45:19 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putbase(uintptr_t nb, int base, int up)
{
	int			count;
	const char	*digits;

	count = 0;
	if (up)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (nb == (unsigned long long)-2147483648)
	{
		write(1, "-2147483648", 12);
		return (11);
	}
	if (nb >= (unsigned long long)base)
		count += ft_putbase(nb / base, base, up);
	ft_putchar(digits[nb % base]);
	count++;
	return (count);
}
