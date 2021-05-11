/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_liba_no_cry.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:41:14 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:02:38 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_cntd(char c, int *printed_counter)
{
	*printed_counter += (int)write(1, &c, sizeof(char));
}

void	ft_putstr_counted(char *str, t_print *prntf)
{
	if (str && *str)
	{
		while (*str)
		{
			ft_putchar_cntd(*str, &(prntf->printed_counter));
			str++;
		}
	}
}

void	ft_upper_or_lower(long long int num, t_print *prntf)
{
	if (prntf->type == 'X')
		ft_putchar_cntd(num % 16 + '7', &(prntf->printed_counter));
	else
		ft_putchar_cntd(num % 16 + 'W', &(prntf->printed_counter));
}

int		ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int		ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
