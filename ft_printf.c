/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:43:40 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:02:38 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_print	prntf;
	va_list	arguments;
	int		pos;

	if (!str)
		return (0);
	pos = 0;
	ft_struct_init(&prntf);
	va_start(arguments, str);
	pos = ft_specificator(str, &prntf, arguments, pos);
	va_end(arguments);
	if (pos == -1)
		return (-1);
	return (prntf.printed_counter);
}

int	ft_specificator(const char *str, t_print *prntf, va_list arguments, int pos)
{
	while (str[pos] != '\0')
	{
		if (str[pos] == '%')
		{
			pos++;
			if (str[pos] == '\0')
				break ;
			else
			{
				if ((pos = ft_str_parser(str, prntf, arguments, pos)) == -1)
					break ;
				ft_struct_clean(prntf);
			}
		}
		else
			ft_putchar_cntd(str[pos], &(prntf->printed_counter));
		pos++;
	}
	return (pos);
}
