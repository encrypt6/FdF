# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 14:39:19 by elsikira          #+#    #+#              #
#    Updated: 2024/06/21 17:41:17 by elsikira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = main.c key_hook_utils.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I. -ILIBFT -IMINILIBX
LIBFT = Libft/libft.a
MINILIBX = minilibx-linux/libmlx.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(MINILIBX): minilibx-linux
	make -C minilibx-linux

$(LIBFT): Libft
	make -C Libft

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx-linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)
	make fclean -C Libft
	make clean -C minilibx-linux

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
