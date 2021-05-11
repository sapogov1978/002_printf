/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:26:34 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 21:45:19 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_i_d(t_print *prntf, va_list arguments)
{
	int				i;
	long long int	arg;
	int				negative_crutch;

	arg = va_arg(arguments, int);
	i = prntf->printed_counter;
	if (arg < 0)
		negative_crutch = (ft_numlen(arg) - 1);
	else
		negative_crutch = ft_numlen(arg);
	if (prntf->accuracy > 0 && prntf->accuracy > negative_crutch)
	{
		if (prntf->flag == '-' || prntf->width < 0)
			ft_accuracy_and_left(prntf, arg);
		else
			ft_accuracy_and_right(prntf, arg);
	}
	else
		ft_no_accuracy(prntf, arg, i);
	return (1);
}
