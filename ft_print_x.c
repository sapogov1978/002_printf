/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:26:34 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:01:05 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_x(t_print *prntf, va_list arguments)
{
	int				i;
	unsigned int	arg;

	arg = va_arg(arguments, unsigned int);
	i = prntf->printed_counter;
	if (prntf->accuracy > 0 && prntf->accuracy > ft_numlen_x(arg))
	{
		if (prntf->flag == '-' || prntf->width < 0)
			ft_accuracy_and_left_x(prntf, arg);
		else
			ft_accuracy_and_right_x(prntf, arg);
	}
	else
		ft_no_accuracy_x(prntf, arg, i);
	return (1);
}
