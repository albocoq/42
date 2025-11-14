/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:21:30 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/07 12:21:56 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc(char **ptr, size_t new_size)
{
	char	**new_ptr;
	size_t	i;

	new_ptr = (char **)malloc(new_size);
	if (!new_ptr)
		return (NULL);
	i = 0;
	while (ptr && ptr[i] && i < (new_size / sizeof(char *)))
	{
		new_ptr[i] = ptr[i];
		i++;
	}
	while (i < (new_size / sizeof(char *)))
	{
		new_ptr[i] = NULL;
		i++;
	}
	free(ptr);
	return (new_ptr);
}
