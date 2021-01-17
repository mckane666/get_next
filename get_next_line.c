/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:24:42 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/01/17 17:52:37 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{	
	static int len = 0;
	int j = 0;
	char temp[BUFFER_SIZE  - len];
	static char new_line[BUFFER_SIZE + 1];
	if ((fd > 3 || fd < 0) || !line || BUFFER_SIZE <= 0)
		return (-1);

	read(fd, new_line, BUFFER_SIZE);
	while (new_line[len] != '\n')
	{
		if (new_line[len] == '\0')
			return (0);
		temp[j++] = new_line[len++];
	}
	len++;
	temp[j] = '\0';
	printf("%s\n", temp);
	//printf("len=%d fd=%d BUFFER=%d\n", len, fd, BUFFER_SIZE - len);
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	fd = open(argv[1],O_RDONLY);
	
	//printf("%d\n",fd);
	printf("%d\n", get_next_line(45, &line));

	printf("%d\n", get_next_line(fd, &line));
	printf("%d\n", get_next_line(fd, &line));
	printf("%d\n", get_next_line(fd, &line));
	printf("%d\n", get_next_line(fd, &line));
	printf("%d\n", get_next_line(fd, &line));
	printf("%d\n", get_next_line(fd, &line));
	printf("%d\n", get_next_line(fd, &line));
	printf("%d\n", get_next_line(fd, &line));
	printf("%d\n", get_next_line(fd, &line));
}
