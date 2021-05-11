/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:42:53 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:02:38 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c_percent(t_print *prntf, va_list arguments)
{
	if (prntf->flag == '-' || prntf->width < 0)
	{
		if (prntf->width < 0)
			prntf->width *= -1;
		if (prntf->type == 'c')
			ft_putchar_cntd(va_arg(arguments, int), &(prntf->printed_counter));
		else
			ft_putchar_cntd('%', &(prntf->printed_counter));
		ft_putspacer_cntd(prntf, prntf->width, 1, ' ');
	}
	else if (prntf->flag == '0' && prntf->width > 1 && prntf->type == '%')
	{
		ft_putspacer_cntd(prntf, prntf->width, 1, '0');
		ft_putchar_cntd('%', &(prntf->printed_counter));
	}
	else
	{
		ft_putspacer_cntd(prntf, prntf->width, 1, ' ');
		if (prntf->type == 'c')
			ft_putchar_cntd(va_arg(arguments, int), &(prntf->printed_counter));
		else
			ft_putchar_cntd('%', &(prntf->printed_counter));
	}
	return (1);
}
