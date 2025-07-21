/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:40:10 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/06 09:47:47 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ishighercase(int a)
{
	return (a >= 'A' && a <= 'Z');
}

int	ft_tolower(int c)
{
	if (ft_ishighercase(c))
		return (c += 32);
	return (c);
}
