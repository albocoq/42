/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:42:46 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/22 09:55:09 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	char	*copy;
	size_t	count;

	s_len = 0;
	count = 0;
	while (s[s_len])
		s_len++;
	copy = (char *)malloc((s_len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (count < s_len)
	{
		copy[count] = f((unsigned int)count, s[count]);
		count++;
	}
	copy[count] = 0;
	return (copy);
}
