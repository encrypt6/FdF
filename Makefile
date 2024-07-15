# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 14:39:19 by elsikira          #+#    #+#              #
#    Updated: 2024/07/12 20:22:37 by elsikira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m

NAME = fdf

MAIN_SRC = main.c

SRCS = errors_management.c init.c key_hook_utils.c

LIBFT_PATH = libft
MINILIBX_PATH = minilibx-linux

OBJS = $(SRCS:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)

CC = cc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g3 -Iinclude -I$(LIBFT_PATH) -I$(MINILIBX_PATH)
all: libft minilibx $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MAIN_OBJ) -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
	@printf "$(GREEN)Compilation of fdf is complete.\n\033[0m"

libft:
	$(MAKE) -C $(LIBFT_PATH)
	@printf "$(GREEN)Compilation of libft is complete.\n\033[0m"

minilibx:
	$(MAKE) -C $(MINILIBX_PATH)
	@printf "$(GREEN)Compilation of minilibx is complete.\n\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(MAIN_OBJ)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(MINILIBX_PATH)
	@printf "$(GREEN)All files are cleaned.\n\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)
	@printf "$(GREEN)All files are cleaned.\n\033[0m"

re: fclean all

.PHONY: all clean fclean re libft minilibx
