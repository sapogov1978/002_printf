# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brattles <brattles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 14:00:50 by brattles          #+#    #+#              #
#    Updated: 2021/01/31 23:03:04 by brattles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	all clean fclean re debug
.SUFFIXES:
.SUFFIXES: .c .o .h .d

NAME	= libftprintf.a

FUNCTIONS	= ft_printf.c \
			  ft_printf_utils_00_norm.c \
			  ft_printf_utils_01_is.c \
			  ft_printf_utils_02_my.c \
			  ft_printf_utils_03_pain.c \
			  ft_str_parser.c \
			  ft_str_parser_utils.c \
			  ft_print_c_percent.c \
			  ft_print_i_d.c \
			  ft_print_s.c \
			  ft_print_u.c \
			  ft_print_x.c \
			  ft_print_ptr.c \
			  ft_crunches_run.c \
			  ft_no_liba_no_cry.c \
			  ft_no_liba_no_cry_even_more.c

OBJ			= $(patsubst %.c, %.o, $(FUNCTIONS))
D_FILE		= $(patsubst %.c, %.d, $(FUNCTIONS))
CFLAGS		= -Wall -Wextra -Werror
CC			= gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $?
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@ -MD
include $(wildcard $(D_FILE))

clean:
	rm -f $(OBJ)
	rm -f $(D_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all