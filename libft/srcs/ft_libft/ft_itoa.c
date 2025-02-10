/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:17:52 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/10 16:40:36 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s);

static char	*ft_end(int n, char *a, t_start start)
{
	if (n == 0)
	{
		a[0] = '0';
		return (a);
	}
	if (start.is_negative)
	{
		n = -n;
		a[0] = '-';
	}
	while (n)
	{
		a[--start.count] = (n % 10) + '0';
		n /= 10;
	}
	return (a);
}

static t_start	ft_start(int n)
{
	int		count;
	int		temp_n;
	int		is_negative;
	t_start	a;

	temp_n = n;
	is_negative = 0;
	count = 0;
	if (n < 0)
		is_negative = 1;
	if (n == 0)
		count = 1;
	else
	{
		while (temp_n != 0)
		{
			temp_n /= 10;
			count++;
		}
	}
	if (is_negative)
		count++;
	a.count = count;
	a.is_negative = is_negative;
	return (a);
}

char	*ft_itoa(int n)
{
	char	*a;
	t_start	start;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	start = ft_start(n);
	a = (char *)malloc((start.count + 1) * sizeof(char));
	if (!a)
		return (NULL);
	a[start.count] = '\0';
	return (ft_end(n, a, start));
}

// int main()
// {
// 	char *a = ft_itoa(-2147483648LL);
// 	printf("%s", a);
// }