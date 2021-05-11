/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_03_pain.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:41:14 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:41:15 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspacer_ptr(int space, t_print *prntf)
{
	while (space > 0)
	{
		ft_putchar_cntd(' ', &(prntf->printed_counter));
		space--;
	}
}

void	ft_print_hex(char *hex, int len, t_print *prntf, char *str_arg)
{
	int i;
	int start;

	start = 0;
	i = 0;
	prntf->hex_len += ft_strlen_hex(hex) + 2;
	if (prntf->width > 0 && prntf->flag != '-' && str_arg != NULL)
		ft_after_pr(prntf, str_arg, len);
	if (str_arg != NULL)
	{
		ft_putstr_counted("0x", prntf);
		while (i <= len)
		{
			if (hex[i] == '0' && start != 1)
				i++;
			else
			{
				ft_putchar_cntd(hex[i], &(prntf->printed_counter));
				start = 1;
				i++;
			}
		}
	}
	else
		ft_print_hex_null(prntf);
}

void	ft_after_pr(t_print *prntf, char *str_arg, int len)
{
	int space;
	int digit;

	if (str_arg == NULL)
		space = ((prntf->width - len) <= 0) ? 2 : (prntf->width - (len + 1));
	else
	{
		digit = (prntf->hex_len == 0) ? len - 1 : prntf->hex_len;
		space = ((prntf->width - digit) <= 0) ? 0 : (prntf->width - digit);
	}
	ft_putspacer_ptr(space, prntf);
}
