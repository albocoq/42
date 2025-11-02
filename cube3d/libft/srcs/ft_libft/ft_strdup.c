/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:54:46 by aboussem          #+#    #+#             */
/*   Updated: 2025/11/01 23:18:36 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*a;

	a = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	ft_strlcpy(a, s, ft_strlen(s) + 1);
	return (a);
}
