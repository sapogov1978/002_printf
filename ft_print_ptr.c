/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:26:34 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 21:46:33 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_ptr(t_print *prntf, va_list arguments)
{
	char			*str_arg;
	int				i;
	int				len;
	unsigned long	p;
	char			hex[17];

	str_arg = va_arg(arguments, char *);
	p = (unsigned long)str_arg;
	len = 2 * sizeof(p);
	i = len;
	hex[i] = '\0';
	i--;
	while (i >= 0)
	{
		hex[i] = "0123456789abcdef"[p & 0x0F];
		p >>= 4;
		i--;
	}
	ft_hex_check(hex, len, prntf, str_arg);
	return (1);
}
