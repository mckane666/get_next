/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:24:42 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/01/26 11:41:10 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char cutnew(char **l, int fd, int r)
{	
	char *tempo;
	int len;
	printf("+++%s%s",l[fd], "FIM");
	while (l[fd][len] != '\n' && l[fd][len] != '\0')
		len++;
	tempo[len] = 'Z';
	while (len + 1)
		tempo[len--] = l[fd][len];
	printf("----->%s", tempo);
	printf("fdgdfgddffghdfh");
	//return (temp);*/
	
}	

int	get_next_line(int fd, char **line)    //ola\0mun\0doc\0rue\0l\0
{
	int r;
	static char *new_line[4096];
	char buf[BUFFER_SIZE + 1];
	char *temp;

	if (fd < 0 && fd < 3 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((r = read(fd, buf, BUFFER_SIZE)) > 0)
	{	
		buf[r] = '\0';
		if (!new_line[fd]) //temp??
			new_line[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(new_line[fd], buf);
			free(new_line[fd]);
			new_line[fd] = temp;
			if (ft_strchr(buf, '\n'))
				break ;
		}
	}
	printf("-->%s", new_line[fd]);
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	
	printf("%d\n", fd);
	printf("%d\n", get_next_line(fd, &line));
	printf("%d\n", get_next_line(fd, &line));
	
}
