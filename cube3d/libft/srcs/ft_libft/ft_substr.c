/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:29:42 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/11 15:43:19 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	count;

	count = 0;
	if (start >= ft_strlen(s))
	{
		newstr = (char *)malloc(sizeof(char));
		if (newstr == NULL)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s[start + count] && count < len)
	{
		newstr[count] = s[start + count];
		count++;
	}
	newstr[count] = '\0';
	return (newstr);
}
