/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:17:49 by elsikira          #+#    #+#             */
/*   Updated: 2024/01/04 14:49:29 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stddef.h>
# include <strings.h>
# include <ctype.h>
# include <string.h>

//ft_printf.c
size_t		ft_strlen(const char *str);
int			ft_is_p(void *value);
int			ft_printf(const char *formatt, ...);
//ft_functions.c
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr_base(unsigned int nbr, char *base);
int			ft_putnbr_basep(unsigned long nbr, char *base);
int			ft_putnbr(long long nbr);

#endif
