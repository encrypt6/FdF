/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:46:06 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/12 20:17:38 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(void)
{
	ft_dprintf(STDERR_FILENO, "Error : invalid number of parameter\n");
	exit(1);
}

int	check_file(char **argv)
{
	const char *ext;

	ext = ft_strrchr(argv[1], '.');
	if (ext != NULL && ft_strcmp(ext, ".fdf") == 0)
		return (0);
	else
		return (1);
}

int check_argc(int argc)
{
	if (argc == 2)
		return (0);
	else
		return (1);
}

void	check_all_errors(int argc, char **argv)
{
	if (check_argc(argc))
		print_error();	
	if (check_file(&argv[1]))
		print_error();	
}
