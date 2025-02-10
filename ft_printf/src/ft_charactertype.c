/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charactertype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:02:36 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/18 09:51:39 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_charactertype(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar(c);
	return (1);
}
