/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:14:45 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/13 17:50:53 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, nmemb * size);
	return (array);
}

// int main()
// {
//     size_t count = 5;
//     size_t size = sizeof(int);

//     int *array1 = (int *)ft_calloc(count, size);
//     if (array1 == NULL)
//     {
//         printf("Erreur d'allocation de mémoire\n");
//         return 1;
//     }

//     printf("Test 1 - Array despues ft_calloc:\n");
//     printf("array1[0] = %d\n", array1[0]);
//     printf("array1[1] = %d\n", array1[1]);
//     printf("array1[2] = %d\n", array1[2]);
//     printf("array1[3] = %d\n", array1[3]);
//     printf("array1[4] = %d\n", array1[4]);

//     int *array2 = (int *)calloc(count, size);
//     if (array2 == NULL)
//     {
//         printf("Erreur d'allocation de mémoire\n");
//         free(array1);
//         return 1;
//     }

//     printf("\nTest 2 - Array despues calloc (standard):\n");
//     printf("array2[0] = %d\n", array2[0]);
//     printf("array2[1] = %d\n", array2[1]);
//     printf("array2[2] = %d\n", array2[2]);
//     printf("array2[3] = %d\n", array2[3]);
//     printf("array2[4] = %d\n", array2[4]);

//     free(array1);
//     free(array2);
//     return 0;
// }