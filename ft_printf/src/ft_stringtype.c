/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringtype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:02:36 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/18 10:32:01 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_stringtype(va_list args)
{
	int		count;
	char	*c;

	count = 0;
	c = va_arg(args, char *);
	if (c == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (c[count])
	{
		ft_putchar(c[count]);
		count++;
	}
	return (count);
}
