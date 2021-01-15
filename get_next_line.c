/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:24:42 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/01/11 12:51:05 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	printf("%s", line);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	char text[BUFFER_SIZE + 1];

	fd = open(argv[1],O_RDONLY);
	
	printf("%d\n",fd);
	i = read(fd, text, BUFFER_SIZE);
	printf("%d\n",i);
	text[i] = '\0';
	//printf("%s",temp);
	get_next_line(fd, text);

}
