# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 10:11:08 by elsikira          #+#    #+#              #
#    Updated: 2024/08/19 14:50:15 by elsikira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

SRCS_DIRS = conversion ctype memory put stdio string utils

# Adjust paths for sources to ensure they are correctly referenced
SRCS = $(addprefix conversion/, ft_atoi.c ft_itoa.c) \
       $(addprefix ctype/, ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c) \
       $(addprefix memory/, free_buffer.c ft_bzero.c ft_memchr.c ft_calloc.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_memmove.c) \
       $(addprefix put/, ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_base_fd.c ft_putnbr_base_p_fd.c ft_putstr_fd.c ft_putpointer_fd.c) \
       $(addprefix stdio/, ft_dprintf.c) \
       $(addprefix string/, ft_split.c ft_strchr.c ft_strdup.c ft_strcmp.c ft_striteri.c ft_strjoin.c ft_strlen.c ft_strlcat.c ft_strmapi.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c) \
       $(addprefix utils/, ft_hexlen.c ft_nbrlen.c ft_ptrlen.c ft_swap.c get_first_line.c get_next_line.c)

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# The pattern rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

