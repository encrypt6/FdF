/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:56:11 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/15 15:28:19 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H 

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define ESC_KEY 65307

# include "libft/libft.h"
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"

int		main(int argc, char **argv);

void	check_all_errors(int argc, char **argv);

void	launch_fdf(void);

int		key_hook(int key_code, void *param);

#endif
