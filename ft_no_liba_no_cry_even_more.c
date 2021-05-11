/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_liba_no_cry_even_more.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:41:14 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:02:38 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_counted(long long int nb, t_print *prntf)
{
	if (nb < 0)
	{
		ft_putchar_cntd('-', &(prntf->printed_counter));
		nb *= -1;
		ft_putnbr_counted(nb, prntf);
	}
	else if (nb >= 0 && nb < 10)
	{
		ft_putchar_cntd(nb + '0', &(prntf->printed_counter));
	}
	else if (nb >= 10)
	{
		ft_putnbr_counted(nb / 10, prntf);
		ft_putchar_cntd(nb % 10 + '0', &(prntf->printed_counter));
	}
}

void	ft_putnbr_counted_x(long long int nb, t_print *prntf)
{
	if (nb >= 16)
	{
		ft_putnbr_counted_x((nb / 16), prntf);
		if ((nb % 16) < 10)
			ft_putchar_cntd(nb % 16 + '0', &(prntf->printed_counter));
		else
			ft_upper_or_lower(nb, prntf);
	}
	else
	{
		if ((nb % 16) < 10)
			ft_putchar_cntd(nb + '0', &(prntf->printed_counter));
		else
			ft_upper_or_lower(nb, prntf);
	}
}

int		ft_numlen(long long int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	if (nb == 0 || nb < 10)
		return ((i + 1));
	else
	{
		while (nb)
		{
			nb /= 10;
			i++;
		}
	}
	return (i);
}

int		ft_numlen_x(long long int nb)
{
	int i;

	i = 0;
	if (nb >= 0 && nb < 17)
		return (1);
	else
	{
		while (nb)
		{
			nb /= 16;
			i++;
		}
	}
	return (i);
}

void	ft_putspacer_cntd(t_print *prntf, int count, int min, char c)
{
	int i;

	i = count;
	if (i < 0)
		i *= -1;
	while (i > min)
	{
		ft_putchar_cntd(c, &(prntf->printed_counter));
		i--;
	}
}
