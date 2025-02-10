/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:38:37 by aboussem          #+#    #+#             */
/*   Updated: 2025/02/10 09:38:02 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words_quotes(char *str)
{
	int	count;
	int	i;
	int	in_quotes;

	count = 0;
	i = 0;
	in_quotes = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
			count++;
		while (str[i] && ((str[i] != ' ' && str[i] != '\t') || in_quotes))
		{
			if (str[i] == '\'' || str[i] == '\"')
				in_quotes = !in_quotes;
			i++;
		}
	}
	return (count);
}

static int	process_word(char *str, int *i, char **result, int j)
{
	int	start;
	int	in_quotes;

	in_quotes = 0;
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		(*i)++;
	start = *i;
	while (str[*i] && ((str[*i] != ' ' && str[*i] != '\t') || in_quotes))
	{
		if (str[*i] == '\'' || str[*i] == '\"')
			in_quotes = !in_quotes;
		(*i)++;
	}
	if (*i > start)
		result[j++] = ft_substr(str, start, *i - start);
	return (j);
}

char	**split_cmd(char *str)
{
	char	**result;
	int		i;
	int		j;

	result = malloc(sizeof(char *) * (count_words_quotes(str) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
		j = process_word(str, &i, result, j);
	result[j] = NULL;
	return (result);
}
