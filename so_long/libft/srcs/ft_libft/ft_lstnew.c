/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:50:46 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/13 16:11:24 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = malloc(sizeof(t_list));
	if (!nodo)
		return (NULL);
	nodo->content = content;
	nodo->next = NULL;
	return (nodo);
}

// int main()
// {
//     int i = 42;
//     t_list *node = ft_lstnew(&i);
//     if (node)
//     {
//         printf("Content: %s\n", (unsigned char *)node->content);  
// Affiche le contenu du noeud
//         free(node->content);  // Libération de la mémoire du contenu
//         free(node);  // Libération de la mémoire du noeud
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }
//     return 0;
// }