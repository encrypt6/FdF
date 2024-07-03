# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 16:55:29 by elsikira          #+#    #+#              #
#    Updated: 2024/01/04 12:17:20 by elsikira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_functions.c

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re