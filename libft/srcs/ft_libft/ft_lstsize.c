/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:24:45 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/13 16:10:25 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int				lstlen;
	struct s_list	*next;

	lstlen = 0;
	next = lst;
	while (next != NULL)
	{
		next = next->next;
		lstlen++;
	}
	return (lstlen);
}
