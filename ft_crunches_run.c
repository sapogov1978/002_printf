/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crunches_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:41:14 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:03:47 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left_crunch(t_print *prntf, long long int arg)
{
	if (arg == 0 && prntf->accuracy == 0 && prntf->have_dot_fl == 1)
		arg = 0;
	else
		ft_putnbr_counted(arg, prntf);
}

void	ft_right_crunch(t_print *prntf, long long int arg)
{
	if (arg == 0 && prntf->accuracy == 0 && prntf->have_dot_fl == 1)
		arg = 0;
	else
		ft_putnbr_counted_x(arg, prntf);
}
