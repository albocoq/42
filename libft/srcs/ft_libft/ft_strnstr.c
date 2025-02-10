/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:30:37 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/11 15:15:14 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lenlittle;
	size_t	i;
	size_t	j;

	lenlittle = ft_strlen(little);
	if (lenlittle == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0] && i + lenlittle <= len)
		{
			j = 1;
			while (little[j] && big[i + j] == little[j] && i + j < len)
				j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
//     printf("%s\n", ft_strnstr("abcd", "abcd", 20));
//     printf("%s\n", ft_strnstr("abcd", "bc", 3));
//     printf("%s\n", ft_strnstr("abcd", "ef", 20));
// }