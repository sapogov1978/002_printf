/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_02_my.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:41:14 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:44:26 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_accuracy_and_left_x(t_print *prntf, long long int arg)
{
	int		i;

	i = prntf->printed_counter;
	if (arg < 0)
	{
		ft_putchar_cntd('-', &(prntf->printed_counter));
		arg *= -1;
		ft_putspacer_cntd(prntf, prntf->accuracy, ft_numlen_x(arg), '0');
		ft_putnbr_counted_x(arg, prntf);
		i = prntf->printed_counter - i;
		ft_putspacer_cntd(prntf, prntf->width, i, ' ');
	}
	else
	{
		ft_putspacer_cntd(prntf, prntf->accuracy, ft_numlen_x(arg), '0');
		ft_putnbr_counted_x(arg, prntf);
		i = prntf->printed_counter - i;
		ft_putspacer_cntd(prntf, prntf->width, i, ' ');
	}
}

void	ft_accuracy_and_right_x(t_print *prntf, long long int arg)
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
		ft_putspacer_cntd(prntf, prntf->accuracy, ft_numlen_x(arg), '0');
		if (arg == 0 && prntf->accuracy == 0 && prntf->width != 0
			&& prntf->have_dot_fl == 1)
			ft_putchar_cntd(' ', &(prntf->printed_counter));
		ft_right_crunch(prntf, arg);
	}
	else
		ft_number_output_x(prntf, arg, '0', prntf->accuracy);
}

void	ft_no_accuracy_x(t_print *prntf, long long int arg, int i)
{
	if (prntf->flag == '-' || prntf->width < 0)
	{
		if (prntf->width < 0)
			prntf->width = prntf->width * -1;
		ft_right_crunch(prntf, arg);
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
			ft_putspacer_cntd(prntf, prntf->width, (ft_numlen_x(arg) + 1), '0');
			ft_putnbr_counted_x(arg, prntf);
		}
		else
			ft_number_output_x(prntf, arg, '0', prntf->width);
	}
	else
		ft_number_output_x(prntf, arg, ' ', prntf->width);
}

void	ft_number_output_x(t_print *prntf, long long int arg, char c, int check)
{
	while (check-- > ft_numlen_x(arg))
		ft_putchar_cntd(c, &(prntf->printed_counter));
	if (arg == 0 && prntf->accuracy == 0 && prntf->width != 0
		&& prntf->have_dot_fl == 1)
		ft_putchar_cntd(' ', &(prntf->printed_counter));
	ft_right_crunch(prntf, arg);
}

void	ft_hex_check(char *hex, int len, t_print *prntf, char *str_arg)
{
	int		space;

	space = 0;
	if (prntf->flag == '-')
	{
		if (prntf->width >= 0)
		{
			if (str_arg == NULL)
			{
				space = (prntf->width <= len) ? 0 : ((prntf->width - len));
				ft_print_hex(hex, len - 1, prntf, str_arg);
			}
			else
			{
				ft_print_hex(hex, len - 1, prntf, str_arg);
				space = ((prntf->width - prntf->hex_len) < 0) ? \
				0 : (prntf->width - prntf->hex_len);
			}
		}
	}
	else
		ft_print_hex(hex, len - 1, prntf, str_arg);
	if (str_arg != NULL)
		ft_putspacer_ptr(space, prntf);
}
