/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:00:41 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/05 11:00:50 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*dup_trim_ws(const char *s)
{
	char	*out;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s)
		return (NULL);
	while (s[start] && (s[start] == ' '
			|| s[start] == '\t' || s[start] == '\n'))
		start++;
	end = ft_strlen(s);
	while (end > start && (s[end - 1] == ' '
			|| s[end - 1] == '\t' || s[end - 1] == '\n'))
		end--;
	out = (char *)malloc((end - start) + 1);
	if (!out)
		return (NULL);
	ft_memcpy(out, s + start, end - start);
	out[end - start] = '\0';
	return (out);
}
