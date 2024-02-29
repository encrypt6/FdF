# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 10:11:08 by elsikira          #+#    #+#              #
#    Updated: 2023/11/27 10:50:32 by elsikira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_strncmp.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strnstr.c ft_bzero.c ft_memcpy.c ft_memset.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_striteri.c ft_strmapi.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	cc -nostartfiles -shared -o libft.so $(OBJS)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
