/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:43:54 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:03:47 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_parser(const char *str, t_print *prntf, va_list arguments, int pos)
{
	while (str[pos] == '0' || str[pos] == '-')
	{
		if (str[pos] == '-')
			prntf->is_negative_fl = '-';
		prntf->flag = str[pos];
		if (prntf->is_negative_fl == '-')
			prntf->flag = '-';
		pos++;
	}
	pos = ft_wildcard(str, prntf, arguments, pos);
	if (str[pos] == '.')
	{
		prntf->have_dot_fl = 1;
		pos++;
		pos = ft_wildcard(str, prntf, arguments, pos);
	}
	if (ft_type(str[pos]) == 1)
		prntf->type = str[pos];
	else
		return (-1);
	if (ft_str_printer(prntf, arguments) == -1)
		return (-1);
	return (pos);
}

int	ft_str_printer(t_print *prntf, va_list arguments)
{
	int	error;

	error = 1;
	if (prntf->type == 'c' || prntf->type == '%')
		error = ft_print_c_percent(prntf, arguments);
	if (prntf->type == 'i' || prntf->type == 'd')
		error = ft_print_i_d(prntf, arguments);
	if (prntf->type == 's')
		error = ft_print_s(prntf, arguments);
	if (prntf->type == 'x' || prntf->type == 'X')
		error = ft_print_x(prntf, arguments);
	if (prntf->type == 'u')
		error = ft_print_u(prntf, arguments);
	if (prntf->type == 'p')
		error = ft_print_ptr(prntf, arguments);
	return (error);
}
