/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:32:08 by aboussem          #+#    #+#             */
/*   Updated: 2025/11/02 11:46:17 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int				lstsize;
	struct s_list	*next;

	lstsize = ft_lstsize(lst);
	next = lst;
	while (lstsize - 1 > 0)
	{
		next = next->next;
		lstsize--;
	}
	return (next);
}
