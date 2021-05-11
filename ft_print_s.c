/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:19:27 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:03:47 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_s(t_print *prntf, va_list arguments)
{
	char *str_arg;

	str_arg = va_arg(arguments, char *);
	if (!str_arg)
		str_arg = "(null)";
	if (str_arg)
	{
		if (prntf->have_dot_fl == 1)
		{
			if (prntf->accuracy >= ft_strlen(str_arg) || prntf->accuracy < 0)
				ft_justufy(prntf, str_arg);
			else if ((prntf->accuracy > 0) && (prntf->accuracy <
				ft_strlen(str_arg)))
				ft_str_accuracy(prntf, str_arg);
			else
				ft_putspacer_cntd(prntf, prntf->width, 0, ' ');
		}
		else
			ft_justufy(prntf, str_arg);
	}
	else
		ft_putspacer_cntd(prntf, prntf->width, 1, ' ');
	return (1);
}
