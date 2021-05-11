/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:46:00 by brattles          #+#    #+#             */
/*   Updated: 2021/01/31 22:05:39 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_print	t_print;

struct		s_print
{
	char	is_negative_fl;
	char	flag;
	int		width;
	int		have_dot_fl;
	int		accuracy;
	char	type;
	int		printed_counter;
	int		hex_len;
};

int			ft_printf(const char *str, ...);
int			ft_specificator(const char *str, t_print *prntf,
			va_list arguments, int pos);
void		ft_struct_init(t_print *prntf);
void		ft_struct_clean(t_print *prntf);
int			ft_str_parser(const char *str, t_print *prntf,
			va_list arguments, int pos);
int			ft_type(char c);
int			ft_wildcard(const char *str, t_print *prntf,
			va_list arguments, int pos);
int			ft_str_printer(t_print *prntf, va_list arguments);
int			ft_print_i_d(t_print *prntf, va_list arguments);
int			ft_print_c_percent(t_print *prntf, va_list arguments);
int			ft_print_s(t_print *prntf, va_list arguments);
int			ft_print_u(t_print *prntf, va_list arguments);
int			ft_print_x(t_print *prntf, va_list arguments);
int			ft_print_ptr(t_print *prntf, va_list arguments);

void		ft_no_accuracy(t_print *prntf, long long int arg, int i);
void		ft_accuracy_and_right(t_print *prntf, long long int arg);
void		ft_accuracy_and_left(t_print *prntf, long long int arg);
void		ft_number_output(t_print *prntf, long long int arg,
			char c, int check);
void		ft_justufy(t_print *prntf, char *str_arg);
void		ft_str_accuracy(t_print *prntf, char *str_arg);
void		ft_accuracy_and_left_x(t_print *prntf, long long int arg);
void		ft_accuracy_and_right_x(t_print *prntf, long long int arg);
void		ft_no_accuracy_x(t_print *prntf, long long int arg, int i);
void		ft_number_output_x(t_print *prntf, long long int arg,
			char c, int check);
void		ft_hex_check(char *hex, int len, t_print *prntf, char *str_arg);
void		ft_putspacer_ptr(int space, t_print *prntf);
void		ft_print_hex(char *hex, int len, t_print *prntf, char *str_arg);
void		ft_after_pr(t_print *prntf, char *str_arg, int len);
int			ft_print_hex_null(t_print *prntf);
int			ft_strlen_hex(char *hex);

void		ft_putchar_cntd(char c, int *printed_counter);
void		ft_putstr_counted(char *str, t_print *prntf);
void		ft_putnbr_counted(long long int nb, t_print *prntf);
void		ft_putnbr_counted_x(long long int num, t_print *prntf);
void		ft_putspacer_cntd(t_print *prntf, int count, int min, char c);
int			ft_isdigit(int c);
int			ft_strlen(const char *str);
int			ft_numlen(long long int nb);
int			ft_numlen_x(long long int nb);
void		ft_upper_or_lower(long long int num, t_print *prntf);

void		ft_left_crunch(t_print *prntf, long long int arg);
void		ft_right_crunch(t_print *prntf, long long int arg);

#endif
