/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:03:06 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/10 15:17:47 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
}
