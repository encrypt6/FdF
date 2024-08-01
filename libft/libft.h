/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:42:16 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/25 18:48:02 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <assert.h>
# include <limits.h>
# include <errno.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int				ft_atoi(const char *str);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

char			*ft_itoa(int n);

char			*ft_strdup(char *src);

size_t			ft_strlcat(char *dest, const char *src, size_t size);

size_t			ft_strlcpy(char *dest, const char *src, size_t size);

size_t			ft_strlen(const char *str);

size_t			ft_nbrlen(int nbr);

size_t			ft_ptrlen(void *ptr);

size_t			ft_hexlen(unsigned int hex);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

int     		ft_strcmp(const char *s1, const char *s2);

char			*ft_strnstr(const char *big, const char *little, size_t len);

void			*ft_memset(void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memmove(void *dest, const void *src, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

void			*ft_memcpy(void *dest, const void *src, size_t n);

void			ft_bzero(void *s, size_t n);

void			ft_putstr_fd(char *str, int fd);

void			ft_putchar_fd(char c, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putpointer_fd(void *value, int fd);

void			ft_putnbr_base_fd(unsigned int nbr, char *base, int fd);

void			ft_putnbr_base_p_fd(unsigned long nbr, char *base, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int				ft_tolower(int c);

int				ft_toupper(int c);

char			*ft_strchr(const char *s, int c);

char			*ft_strrchr(const char *s, int c);

void			*ft_calloc(size_t nmemb, size_t size);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char *s1, char *s2);

char			*ft_strtrim(char const *s1, char const *set);

char			**ft_split(char const *s, char c);

int				ft_dprintf(int fd, const char *formatt, ...);

char			*get_next_line(int fd);

char			*get_first_line(int fd);
char			*ft_read_file(int fd, char *line);
char			*ft_first_line(char *buffer);
int				ft_getcountline(char *s);

void			ft_swap(int *a, int *b);
#endif
