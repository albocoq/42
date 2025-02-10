/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:54:46 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/22 09:55:09 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strdup(const char *s)
{
	char	*a;

	a = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	ft_strlcpy(a, s, ft_strlen(s) + 1);
	return (a);
}

// int main() {
// 	char *str = "lorem ipsum dolor sit amet";
// 	char *result;
// 	char *base;
// 	base = strdup(str);
// 	result = ft_strdup(str);
// 	// printf("The string base : %s\n", base);
// 	// printf("The string mine : %s", result);
// 	return 0;
// }