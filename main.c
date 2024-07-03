/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:34:45 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/03 14:36:41 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map(char **argv)
{
	if ()
}

int	check_file_ext(char **argv)
{
	
}

int	check_argc(int argc)
{
	if (argc == 2)
		return (1);
	else
		return (0);
}


void	check_all_errors(int argc, char **argv)
{
	if (check_argc(argc))
		perror("Error");
	if (check_file_ext(argv[1]))
		perror("Error");
	if (check_map(argv[1]))
		perror("Error");
}

int	main(int argc, char **argv)
{
	if (check_all_errors(argc, argv) == 0)
		printf("argc, map format and file content are checked, ready to launch fdf\n");
		//launch_fdf(argv[1]);
	else
		perror("Error : invalid argument.\n");
	return (0);
}


