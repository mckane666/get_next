/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:24:42 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/01/27 03:06:53 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*cutnew(char *new_line, char **line)
{
	char	*tempo;
	int		len;

	len = 0;
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
		*line = ft_strdup(new_line);
		
	return (new_line);
}

int		get_next_line(int fd, char **line)
{
	int			r;
	static char	*new_line[4096];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			check;

	check = 0;
	if (((fd < 0 && fd < 3) || !line || BUFFER_SIZE <= 0))
		return (-1);
	while ((r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r] = '\0';
		if (!new_line[fd])
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
	if (ft_strchr(new_line[fd], '\n'))
		check = 1;
	new_line[fd] = cutnew(new_line[fd], line);
	if (r < 0)
		return (-1);
	if ((r == 0 && (!new_line[fd] || ft_strchr(new_line[fd], '\0'))) && !check)
		return (0);
	return (1);
}


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int 	i;

	fd = open(argv[1], O_RDONLY);

	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%d", i);
		printf("line-->%s\n",line);
		free(line);
	}
	free(line);
	if ((i = get_next_line(fd, &line)) == 0)
	{
		printf("%d", i);
		printf("line-->%s\n",line);
		free(line);
	}


/*

	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);*/
}