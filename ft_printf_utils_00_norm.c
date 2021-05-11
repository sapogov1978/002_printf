/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_00_norm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:41:14 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:48:29 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_hex_null(t_print *prntf)
{
	if (prntf->have_dot_fl == 1)
	{
		if (prntf->is_negative_fl == '0' && prntf->width > 2)
			ft_putspacer_cntd(prntf, prntf->width - 2, 0, ' ');
		prntf->printed_counter += write(1, "0x", 2);
		if (prntf->is_negative_fl != '0' && prntf->width > 2)
			ft_putspacer_cntd(prntf, prntf->width - 2, 0, ' ');
	}
	else
	{
		if (prntf->is_negative_fl == '0' && prntf->width > 3)
			ft_putspacer_cntd(prntf, prntf->width - 3, 0, ' ');
		prntf->printed_counter += write(1, "0x0", 3);
		if (prntf->is_negative_fl != '0' && prntf->width > 3)
			ft_putspacer_cntd(prntf, prntf->width - 3, 0, ' ');
	}
	return (0);
}

int		ft_strlen_hex(char *hex)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!hex)
		return (0);
	while (hex[i] == '0')
		i++;
	while (hex[i++] != '\0')
		j++;
	return (j);
}

void	ft_struct_clean(t_print *prntf)
{
	prntf->is_negative_fl = '0';
	prntf->flag = '1';
	prntf->width = 0;
	prntf->have_dot_fl = 0;
	prntf->accuracy = 0;
	prntf->type = 0;
	prntf->hex_len = 0;
}

void	ft_struct_init(t_print *prntf)
{
	prntf->is_negative_fl = '0';
	prntf->flag = '1';
	prntf->width = 0;
	prntf->have_dot_fl = 0;
	prntf->accuracy = 0;
	prntf->type = 0;
	prntf->printed_counter = 0;
	prntf->hex_len = 0;
}

void	ft_accuracy_and_left(t_print *prntf, long long int arg)
{
	int		i;

	i = prntf->printed_counter;
	if (arg < 0)
	{
		ft_putchar_cntd('-', &(prntf->printed_counter));
		arg *= -1;
		ft_putspacer_cntd(prntf, prntf->accuracy, ft_numlen(arg), '0');
		ft_putnbr_counted(arg, prntf);
		i = prntf->printed_counter - i;
		ft_putspacer_cntd(prntf, prntf->width, i, ' ');
	}
	else
	{
		ft_putspacer_cntd(prntf, prntf->accuracy, ft_numlen(arg), '0');
		ft_putnbr_counted(arg, prntf);
		i = prntf->printed_counter - i;
		ft_putspacer_cntd(prntf, prntf->width, i, ' ');
	}
}
