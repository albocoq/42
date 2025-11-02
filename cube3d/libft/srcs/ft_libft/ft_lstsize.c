/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:24:45 by aboussem          #+#    #+#             */
/*   Updated: 2025/11/02 11:46:28 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
