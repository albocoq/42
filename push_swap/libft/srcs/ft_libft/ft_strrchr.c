/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:49:35 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/16 10:51:56 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*lastview;

	lastview = NULL;
	count = 0;
	while (s[count])
	{
		if ((unsigned char)s[count] == (char)c)
			lastview = (char *)&s[count];
		count++;
	}
	if ((char)c == '\0')
		return ((char *)&s[count]);
	return (lastview);
}

// int main()
// {
// 	char a[] = "teste";
// 	char *c = ft_strrchr(a, 1024 + 'e');
// 	printf("%s", c);
// }