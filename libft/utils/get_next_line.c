/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:42:52 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/16 17:44:36 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_getcountline(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (count);
	while (*s && *s != '\n')
	{
		count++;
		s++;
	}
	return (count);
}
/* char	*ft_newline : function to get the new line 
[1] : i is the count of buffer until the '\n'
[2] if buffer[i] equals to 0, free and return NULL
[3] :  
skips the first one 
already read with a ft_calloc of the length of buffer 
(ft_strlen(buffer)), minus i (what is already read)
and last character + 1*/

char	*ft_new_line(char *buffer)
{
	int			i;
	int			j;
	char		*new_line;

	i = ft_getcountline(buffer);
	j = 0;
	if (buffer[i] == 0)
		return (free(buffer), NULL);
	new_line = ft_calloc((ft_strlen(buffer) - i + 1), 1);
	if (!new_line)
		return (NULL);
	i++;
	while (buffer[i])
		new_line[j++] = buffer[i++];
	return (free(buffer), new_line);
}

/*char	*ft_first_line : function to get the first line
[1] : if buffer is empty or equals to a '\0', 
returns NULL
[2] : line equals to a calloc of the len of 
buffer, + '\n' and '\0'
[3] : if line is empty, returns NULL
[4] : while buffer at n bytes read is true and 
isn't equal to '\n',
buffer becomes line and bytes read iterate.
[5] : if buffer at n bytes read is true and 
equals a '\n', line is at bytes read = '\n'
[6] : returns the line
*/

char	*ft_first_line(char *buffer)
{
	int		bytes_read;
	char	*line;

	bytes_read = 0;
	if (!buffer || *buffer == '\0')
		return (NULL);
	line = ft_calloc(ft_getcountline(buffer) + 2, 1);
	if (!line)
		return (NULL);
	while (buffer[bytes_read] && buffer[bytes_read] != '\n')
	{
		line[bytes_read] = buffer[bytes_read];
		bytes_read++;
	}
	if (buffer[bytes_read] && buffer[bytes_read] == '\n')
		line[bytes_read] = '\n';
	return (line);
}
/* char	*ft_read_file : function to read the fds
[1] : ft_calloc if !file, ie it allocates a fixed 
amount of memory and initializes it to zero.
[2] : malloc the BUFFER_SIZE + last character. 
[3] : if number of bytes is -1, must free line and 
buffer and return NULL. 
[4] : puts a '\0' at the end of buffer then calls 
ft_strjoin_free to join the buffer to the line.
[5] : as usual, if line is null, return NULL.
[6] : strchr searching a '\n', if it finds one, break.
[7] : free the buffer and returns the line*/

char	*ft_read_file(int fd, char *line)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	if (!line)
		line = ft_calloc(1, 1);
	buffer = malloc(BUFFER_SIZE + 1);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), line);
}
/*char	*get_next_line : 
[1] : manages two cases : if the fd is invalid (== -1) 
or if BUFFER_SIZE isnt strictly positive, it returns NULL.
[2] : calls the function ft_read_file to read the file descriptor
[3] : if the reading fails, returns NULL.
[4] : then, line is equal to ft_get_first_line(buffer[fd])
[5] : buffer[fd] equals to ft_new_line
[6] : gnl returns line.*/

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_first_line(buffer[fd]);
	buffer[fd] = ft_new_line(buffer[fd]);
	free(buffer[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		count;

// 	count = 0;
// 	fd = open("txt.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		count++;
// 		printf("%s", line);
// 		free (line);
// 		line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }
