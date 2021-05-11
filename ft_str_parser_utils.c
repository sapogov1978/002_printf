/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_parser_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:41:14 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:03:47 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'u' ||
	c == 'p' || c == 's' || c == 'c' || c == '%')
		return (1);
	else
		return (0);
}

int	ft_wildcard(const char *str, t_print *prntf, va_list arguments, int pos)
{
	if (prntf->have_dot_fl)
		while (ft_isdigit(str[pos]) == 1)
			prntf->accuracy = prntf->accuracy * 10 + str[pos++] - '0';
	else
		while (ft_isdigit(str[pos]) == 1)
			prntf->width = prntf->width * 10 + str[pos++] - '0';
	if (str[pos] == '*')
	{
		if (prntf->have_dot_fl)
		{
			if ((prntf->accuracy = va_arg(arguments, int)) < 0)
				prntf->have_dot_fl = 0;
		}
		else
			prntf->width = va_arg(arguments, int);
		pos++;
	}
	return (pos);
}
