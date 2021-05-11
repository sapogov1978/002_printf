/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_01_is.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:41:14 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:47:26 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_accuracy_and_right(t_print *prntf, long long int arg)
{
	if (arg < 0)
	{
		ft_putspacer_cntd(prntf, prntf->width, (prntf->accuracy + 1), ' ');
		ft_putchar_cntd('-', &(prntf->printed_counter));
	}
	else
		ft_putspacer_cntd(prntf, prntf->width, prntf->accuracy, ' ');
	if (arg < 0)
	{
		arg *= -1;
		ft_putspacer_cntd(prntf, prntf->accuracy, ft_numlen(arg), '0');
		if (arg == 0 && prntf->accuracy == 0 && prntf->width != 0
			&& prntf->have_dot_fl == 1)
			ft_putchar_cntd(' ', &(prntf->printed_counter));
		ft_left_crunch(prntf, arg);
	}
	else
		ft_number_output(prntf, arg, '0', prntf->accuracy);
}

void	ft_no_accuracy(t_print *prntf, long long int arg, int i)
{
	if (prntf->flag == '-' || prntf->width < 0)
	{
		if (prntf->width < 0)
			prntf->width = prntf->width * -1;
		ft_left_crunch(prntf, arg);
		i = prntf->printed_counter - i;
		ft_putspacer_cntd(prntf, prntf->width, i, ' ');
	}
	else if ((prntf->flag == '0' && prntf->width >= 0
		&& prntf->have_dot_fl == 0) || (prntf->flag == '0' && prntf->width >= 0
		&& prntf->accuracy < 0))
	{
		if (arg < 0)
		{
			ft_putchar_cntd('-', &(prntf->printed_counter));
			arg *= -1;
			ft_putspacer_cntd(prntf, prntf->width, (ft_numlen(arg) + 1), '0');
			ft_putnbr_counted(arg, prntf);
		}
		else
			ft_number_output(prntf, arg, '0', prntf->width);
	}
	else
		ft_number_output(prntf, arg, ' ', prntf->width);
}

void	ft_number_output(t_print *prntf, long long int arg, char c, int check)
{
	while (check-- > ft_numlen(arg))
		ft_putchar_cntd(c, &(prntf->printed_counter));
	if (arg == 0 && prntf->accuracy == 0 && prntf->width != 0
		&& prntf->have_dot_fl == 1)
		ft_putchar_cntd(' ', &(prntf->printed_counter));
	ft_left_crunch(prntf, arg);
}

void	ft_justufy(t_print *prntf, char *str_arg)
{
	if (prntf->flag == '-' || prntf->width < 0)
	{
		if (prntf->width < 0)
			prntf->width = prntf->width * -1;
		ft_putstr_counted(str_arg, prntf);
		ft_putspacer_cntd(prntf, prntf->width, ft_strlen(str_arg), ' ');
	}
	else
	{
		ft_putspacer_cntd(prntf, prntf->width, ft_strlen(str_arg), ' ');
		ft_putstr_counted(str_arg, prntf);
	}
}

void	ft_str_accuracy(t_print *prntf, char *str_arg)
{
	int i;

	i = prntf->accuracy;
	if (prntf->flag == '-' || prntf->width < 0)
	{
		if (prntf->width < 0)
			prntf->width = prntf->width * -1;
		while (i--)
		{
			ft_putchar_cntd(*str_arg, &(prntf->printed_counter));
			str_arg++;
		}
		ft_putspacer_cntd(prntf, prntf->width, prntf->accuracy, ' ');
	}
	else
	{
		ft_putspacer_cntd(prntf, prntf->width, prntf->accuracy, ' ');
		while (prntf->accuracy-- && *str_arg)
		{
			ft_putchar_cntd(*str_arg, &(prntf->printed_counter));
			str_arg++;
		}
	}
}
