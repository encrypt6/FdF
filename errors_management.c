/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:46:06 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/20 14:46:29 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file(char *argv)
{
	int	map;

	map = open(argv, O_RDONLY);
	if (map == -1)
	{
		perror("Error");
		exit(1);
	}
	if (open(argv, O_RDONLY) == -1)
	{
		perror("Error");
		exit(1);
	}
	close(map);
}

void	check_argc(int argc)
{
	if (argc > 2)
	{
		errno = E2BIG;
		perror("Error");
		exit(1);
	}
	else if (argc < 2)
	{
		ft_dprintf(STDERR_FILENO, "Error: 2 arguments are required\n");
		exit(1);
	}
}

void	check_all_errors(int argc, char **argv)
{
	if (argc != 2)
		check_argc(argc);
	if (argc == 2)
		check_file(argv[1]);
}
