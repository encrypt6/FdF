# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 14:39:19 by elsikira          #+#    #+#              #
#    Updated: 2024/07/03 18:28:28 by elsikira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m

NAME = fdf

MAIN_SRC = main.c

SRCS = errors_management.c init.c key_hook_utils.c

LIBFT_PATH = libft
FT_PRINTF_PATH = ft_printf
MINILIBX_PATH = minilibx-linux

OBJS = $(SRCS:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)

CC = cc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -Iinclude -I. -I$(LIBFT_PATH) -I$(FT_PRINTF_PATH) -I$(MINILIBX_PATH)
all: libft ft_printf minilibx $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MAIN_OBJ) -L$(LIBFT_PATH) -lft -L$(FT_PRINTF_PATH) -lftprintf -L$(MINILIBX_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
	@printf "$(GREEN)Compilation of fdf is complete.\n\033[0m"

libft:
	$(MAKE) -C $(LIBFT_PATH)
	@printf "$(GREEN)Compilation of libft is complete.\n\033[0m"

ft_printf:
	$(MAKE) -C $(FT_PRINTF_PATH)
	@printf "$(GREEN)Compilation of ft_printf is complete.\n\033[0m"

minilibx:
	$(MAKE) -C $(MINILIBX_PATH)
	@printf "$(GREEN)Compilation of minilibx is complete.\n\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(MAIN_OBJ)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(FT_PRINTF_PATH)
	$(MAKE) clean -C $(MINILIBX_PATH)
	@printf "$(GREEN)All files are cleaned.\n\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(MAKE) fclean -C $(FT_PRINTF_PATH)
	$(MAKE) fclean -C $(MINILIBX_PATH)
	@printf "$(GREEN)All files are cleaned.\n\033[0m"

re: fclean all

.PHONY: all clean fclean re libft minilibx
