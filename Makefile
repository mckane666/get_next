# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 11:26:37 by jhenriqu          #+#    #+#              #
#    Updated: 2021/01/08 12:58:59 by jhenriqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
ifndef $(TAM)
	TAM = 100
endif

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=TAM
SRCS = get_next_line.c get_next_line_utils.c

all:
	@echo $(TAM)
	$(CC) $(CFLAGS) $(SRCS)

bonus:
	$(CC) $(CFLAGS) $(SRCS)

clean:
	rm -rf a.out
fclean: clean
	rm -rf a.out

re: fclean all
