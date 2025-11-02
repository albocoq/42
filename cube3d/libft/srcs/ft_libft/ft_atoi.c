/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:35:06 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/11 12:32:06 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	count;
	int	sign;
	int	value;

	count = 0;
	sign = 1;
	value = 0;
	while (ft_isspace(nptr[count]))
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign *= -1;
		count++;
	}
	while (nptr[count] && ft_isdigit(nptr[count]))
	{
		value = value * 10;
		value += (nptr[count] - '0');
		count++;
	}
	return (value * sign);
}
