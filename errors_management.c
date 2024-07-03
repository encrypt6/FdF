/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:46:06 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/03 16:20:57 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

/*int	check_map(char **argv)
{
	if ()
}

int	check_file_ext(char **argv)
{
	if (
	return(8);	
}*/

int check_argc(int argc)
{
	if (argc == 2)
		return (0);
	else
		return (1);
}

void	check_all_errors(int argc, char **argv)
{
	(void)argv;
	if (check_argc(argc))
		print_error();	
	//if (check_file_ext(argv[1]))
		//perror("Error");
	//if (check_map(argv[1]))
		//perror("Error");
}
