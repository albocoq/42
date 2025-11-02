/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:20:56 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/06 14:10:29 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*catsecond(char const *s2, char	*newarray, int count, int totallen)
{
	int	count2;

	count2 = 0;
	while (count < totallen)
	{
		newarray[count] = s2[count2];
		count++;
		count2++;
	}
	newarray[count] = 0;
	return (newarray);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*newarray;
	int		count;

	s1len = 0;
	s2len = 0;
	count = 0;
	while (s1[s1len])
		s1len++;
	while (s2[s2len])
		s2len++;
	newarray = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (newarray == NULL)
		return (NULL);
	while (s1[count])
	{
		newarray[count] = s1[count];
		count++;
	}
	return (catsecond(s2, newarray, count, (s1len + s2len)));
}
