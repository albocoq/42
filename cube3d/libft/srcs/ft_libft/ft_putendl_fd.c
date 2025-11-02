/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:15:14 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/10 15:45:13 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
	write(fd, "\n", 1);
}
