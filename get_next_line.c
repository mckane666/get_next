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

/*
** recupera valores"perdidos" do buf depois do '\n'
*/
/*
char	*add_to_new(char *str, int len) //Alone, twenty million years from my place.\0A_
{
	int		i;
	char	*temp;
	int		j;

	i = 0;
	j = 0;

	if (!(temp = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (str[len + 1] != '\0') // tiro na tola!!
	{
		temp[i] = str[len];
		i++;
		len++;
	}
	temp[i] = '\0';
	return (temp);
}

//Alone, twenty million years from my place.\n
//Alone, twenty million years\n
//\n
//\0*/
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
	else
		*line = ft_strdup(new_line);
	return (new_line);
}

int		get_next_line(int fd, char **line)
{
	int			r;
	static char	*new_line[4096];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;

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
	if (new_line[fd] == NULL && r > 0)
		return (1);
	new_line[fd] = cutnew(new_line[fd], line);
	if (r < 0)
		return (-1);
	return (!(r == 0 && (!new_line[fd] || new_line[fd][0] == '\0')));
}


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	printf("%d ", get_next_line(fd, &line));
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
	free(line);printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);
	printf("%d", get_next_line(fd, &line));
	printf("line-->%s\n",line);
	free(line);

}
