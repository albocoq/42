/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:32:08 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/13 16:09:35 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	struct s_list	*next;
	int				lstsize;

	lstsize = ft_lstsize(lst);
	next = lst;
	while (lstsize - 1 > 0)
	{
		next = next->next;
		lstsize--;
	}
	return (next);
}
