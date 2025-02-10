/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:35:06 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/22 09:55:09 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_isspace(char a)
{
	return (a == ' ' || a == '\f' || a == '\n'
		|| a == '\r' || a == '\t' || a == '\v');
}

int	ft_atoi(const char *nptr)
{
	int	count;
	int	sign;
	int	value;

	count = 0;
	sign = 1;
	value = 0;
	while (ft_isspace(nptr[count]))
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign *= -1;
		count++;
	}
	while (nptr[count] && ft_isdigit(nptr[count]))
	{
		value = value * 10;
		value += (nptr[count] - '0');
		count++;
	}
	return (value * sign);
}

// int main()
// {
//     printf("ft_atoi test\n");

//     const char *test1 = "42";
//     const char *test2 = "   -123";
//     const char *test3 = "+987";
//     const char *test4 = "   123abc456";
//     const char *test5 = "   -00123";

//     printf("Test 1: \"%s\" => %d\n", test1, ft_atoi(test1));
//     printf("Test 2: \"%s\" => %d\n", test2, ft_atoi(test2));
//     printf("Test 3: \"%s\" => %d\n", test3, ft_atoi(test3));
//     printf("Test 4: \"%s\" => %d\n", test4, ft_atoi(test4));
//     printf("Test 5: \"%s\" => %d\n", test5, ft_atoi(test5));

//     return 0;
// }
