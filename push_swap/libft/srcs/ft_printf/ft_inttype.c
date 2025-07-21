/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:08:13 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/10 10:18:46 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbdigit(int c)
{
	int	len;

	len = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		len++;
	while (c != 0)
	{
		c /= 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr_unsigned(unsigned int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10);
	}
	c = (n % 10) + '0';
	ft_putchar(c);
}

int	ft_inttype(va_list args, char a)
{
	int	num;

	num = va_arg(args, int);
	if (num < 0 && a == 'u')
	{
		ft_putnbr_unsigned((unsigned int)num);
		return (10);
	}
	ft_putnbr(num);
	return (ft_nbdigit(num));
}
