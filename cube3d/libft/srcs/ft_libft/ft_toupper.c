/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:33:42 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/06 09:48:15 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_islowercase(int a)
{
	return (a >= 'a' && a <= 'z');
}

int	ft_toupper(int c)
{
	if (ft_islowercase(c))
		return (c -= 32);
	return (c);
}
