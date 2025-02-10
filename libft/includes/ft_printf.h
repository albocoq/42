/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:06:54 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/10 10:14:34 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(char const *a, ...);
int		ft_inttype(va_list args, char a);
int		ft_charactertype(va_list args);
int		ft_pourcentagetype(void);
int		ft_stringtype(va_list args);
int		ft_pointertype(va_list args, int base);
int		ft_putbase(uintptr_t nb, int base, int up);
int		ft_hexnumbertype(va_list args, char a, int c);

#endif