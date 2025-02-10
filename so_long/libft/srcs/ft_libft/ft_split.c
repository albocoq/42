/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:15:19 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/02 13:12:51 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_all(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_mat(char const *s, char c, char **newmat, int i)
{
	int	start;
	int	y;

	y = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		if (s[i] != '\0')
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			newmat[y] = (char *)malloc((i - start + 1) * sizeof(char));
			if (!newmat[y])
				return (ft_free_all(newmat));
			ft_strlcpy(newmat[y], &s[start], i - start + 1);
			y++;
		}
	}
	newmat[y] = NULL;
	return (newmat);
}

char	**ft_split(char const *s, char c)
{
	char	**newmat;
	int		words_count;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	newmat = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!newmat)
	{
		ft_free_all(newmat);	
		return (NULL);
	}
	return (ft_mat(s, c, newmat, 0));
}

// int main() {
//    char string[50] = "Hello world";
//    // Extract the first token
//    char **mat = ft_split(string, ' ');
//    printf( "mat[0]: %s\n", mat[0] ); //printing the token
//    printf( "mat[1]: %s\n", mat[1] ); //printing the token
//    return 0;
// }