/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:24:42 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/03 02:34:32 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*cutnew(char *new_line, char **line)
{
	char	*tempo;
	int		len;

	len = 0;
	if (new_line == NULL)
	{
		*line = ft_strdup("");
		return (ft_strdup(""));
	}
	while (new_line[len] != '\n' && new_line[len] != '\0')
		len++;
	if (new_line[len] == '\n')
	{
		*line = ft_substr(new_line, 0, len);
		tempo = ft_strdup(&new_line[len + 1]);
		free(new_line);
		new_line = tempo;
	}
	else if (new_line[len] == '\0')
	{
		*line = ft_strdup(new_line);
		free(new_line);
		new_line = ft_strdup("");
	}
	return (new_line);
}

int		r_result(char *new_line, int r, int check)
{
	if (r < 0)
		return (-1);
	if ((r == 0 && (!new_line || ft_strchr(new_line, '\0'))) && !check)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	t_gnl		next;
	static char	*new_line[4096];

	next.check = 0;
	if (!(next.buf = malloc(sizeof(char *) * BUFFER_SIZE + 1)) || (fd < 0 ||
	fd == 1 || fd == 2 || !line || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1))
		return (-1);
	while ((next.r = read(fd, next.buf, BUFFER_SIZE)) > 0)
	{
		next.buf[next.r] = '\0';
		if (!new_line[fd])
			new_line[fd] = ft_strdup(next.buf);
		else
		{
			next.temp = ft_strjoin(new_line[fd], next.buf);
			new_line[fd] = next.temp;
		}
		if (ft_strchr(next.buf, '\n'))
			break ;
	}
	free(next.buf);
	if (ft_strchr(new_line[fd], '\n'))
		next.check = 1;
	new_line[fd] = cutnew(new_line[fd], line);
	return (r_result(new_line[fd], next.r, next.check));
}
/*
int		main(int argc, char **argv)
{

	int		fd;
	int		fd2; //second file
	char	*line;
	int 	i;

	fd2 = 0;
	fd = open(argv[1], O_RDONLY);
	if (argc > 2)
		fd2 = open(argv[2], O_RDONLY); //second file
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%d", i);
		printf("line-->%s\n",line);
		if (line)
			free(line);
	}
	printf("%d", i);
	printf("line-->%s\n",line);
	if (line)
		free(line);
	close(fd);

	if (argc > 2)
	{
		while ((i = get_next_line(fd2, &line)) > 0) //second file
		{
			printf("%d", i);
			printf("line-->%s\n",line);
			if (line)
				free(line);
		}
		printf("%d", i);
		printf("line-->%s\n",line);
		if (line)
			free(line);
		close(fd2);
	}
}
*/