/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:12:59 by aboussem          #+#    #+#             */
/*   Updated: 2024/12/20 09:56:41 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_switch(const char *a, int i, int addvalue, va_list args)
{
	addvalue = ft_strlen(a);
	while (a[i])
	{
		if (a[i] == '%')
		{
			addvalue -= 2;
			i++;
			if (a[i] == 'd' || a[i] == 'i' || a[i] == 'u')
				addvalue += ft_inttype(args, a[i]);
			else if (a[i] == 'c')
				addvalue += ft_charactertype(args);
			else if (a[i] == '%')
				addvalue += ft_pourcentagetype();
			else if (a[i] == 'p')
				addvalue += ft_pointertype(args, 16);
			else if (a[i] == 's')
				addvalue += ft_stringtype(args);
			else if (a[i] == 'x' || a[i] == 'X')
				addvalue += ft_hexnumbertype(args, a[i], 16);
		}
		else
			ft_putchar(a[i]);
		i++;
	}
	return (addvalue);
}

int	ft_printf(char const *a, ...)
{
	va_list	args;
	int		i;
	int		addvalue;

	i = 0;
	addvalue = 0;
	va_start(args, a);
	addvalue = ft_switch(a, i, addvalue, args);
	va_end(args);
	return (addvalue);
}

// int main() {
// 	// Test du format %c
// 	char caractere = 'A';
// 	ft_printf(" %c \n", caractere);
// 	printf(" %c \n\n", caractere);
// 	// Test du format %s
// 	char *chaine = NULL;
// 	ft_printf(" %s \n", chaine);
// 	printf(" %s \n\n", chaine);
// 	// Test du format %p
// 	int nombre = 0;
// 	ft_printf(" %p %p \n", NULL, (void *)&nombre);
// 	printf(" %p %p \n\n", NULL, (void *)&nombre);
// 	// Test du format %d
// 	int entier_decimal = 63;
// 	ft_printf(" %d \n", entier_decimal);
// 	printf(" %d \n\n", entier_decimal);
// 	// Test du format %i
// 	int entier_base10 = 67890;
// 	ft_printf(" %i \n", entier_base10);
// 	printf(" %i \n\n", entier_base10);
// 	// Test du format %u
// 	unsigned int entier_non_signe = -1;
// 	int result = 0;
// 	result = ft_printf(" %u ", entier_non_signe);
// 	printf("%d \n", result);
// 	result = 0;
// 	result = printf(" %u ", entier_non_signe);
// 	printf("%d \n\n", result);
// 	// Test du format %x
// 	int nombre_hex_min = -100;
// 	ft_printf(" %x \n", nombre_hex_min);
// 	printf(" %x \n\n", nombre_hex_min);
// 	// Test du format %X
// 	ft_printf(" %X \n", nombre_hex_min);
// 	printf(" %X \n\n", nombre_hex_min);
// 	// Test du pourcentage %%
// 	ft_printf(" %% \n");
// 	printf(" %% \n\n");
// 	return 0;
// }