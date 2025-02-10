/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:29:42 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/22 09:55:09 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

// int main()
// {
//     char str1[] = "Hola Mundo";
//     char *result1 = ft_substr(str1, 5, 3);
//     printf("Test 1 - ft_substr: %s\n", result1);
//     free(result1);
//     char str2[] = "Hola Mundo";
//     char *result2 = ft_substr(str2, 5, 100);
//     printf("Test 2 - ft_substr: %s\n", result2);
//     free(result2);
//     char str3[] = "Hola Mundo";
//     char *result3 = ft_substr(str3, 20, 5);
//     printf("Test 3 - ft_substr: '%s'\n", result3);
//     free(result3);
//     char str4[] = "Hola Mundo";
//     char *result4 = ft_substr(str4, 0, 0);
//     printf("Test 4 - ft_substr: '%s'\n", result4);
//     free(result4);
//     char str5[] = "Hola Mundo";
//     char *result5 = ft_substr(str5, 0, 4);
//     printf("Test 5 - ft_substr: %s\n", result5);
//     free(result5);
//     return 0;
// }