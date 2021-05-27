# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 10:45:55 by abonnel           #+#    #+#              #
#    Updated: 2021/05/27 12:33:56 by abonnel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	checker.c check_arguments.c push_checker_list_functions.c \
			push_checker_error.c operations_swap_push.c \
			push_checker_instructions.c \
			operations_rotate.c operation_rev_rotate.c push_checker_utils.c

SRCS_PS	=	push_swap.c check_arguments.c push_checker_list_functions.c \
			push_checker_error.c operations_swap_push.c \
			push_checker_instructions.c \
			operations_rotate.c operation_rev_rotate.c push_checker_utils.c \
			push_swap_ranking.c push_swap_sort_iterations.c \
			push_swap_sort_short.c push_swap_sort_utils.c

OBJS	= $(SRCS:.c=.o)

OBJS_PS	= $(SRCS_PS:.c=.o)

NAME	= checker

PS_NAME	= push_swap

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror 

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJS_PS)
			$(MAKE) -C ../libgnl_normv3 && cp ../libgnl_normv3/libft.a .
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L. -lft -g 
			$(CC) $(CFLAGS) $(OBJS_PS) -o $(PS_NAME) -L. -lft -g 

clean:
			$(RM) $(OBJS) $(OBJS_PS)
			$(MAKE) clean -C ../libgnl_normv3

fclean:		clean
			$(RM) $(NAME) $(PS_NAME) libft.a
			$(MAKE) fclean -C ../libgnl_normv3

re:			fclean all

.PHONY:		all clean fclean re
