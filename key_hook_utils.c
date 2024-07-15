/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:38:25 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/15 18:19:57 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int key_code, void *param)
{
	(void)param;
	if (key_code == ESC_KEY)
		exit(0);
	//do with mlx_loop_end
	return (0);
}
