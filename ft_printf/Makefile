# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 18:24:56 by ntesfu            #+#    #+#              #
#    Updated: 2022/01/27 22:16:29 by ntesfu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*-MakeFile -*-

DIRSRC		= ./

DIRINC		= ./

DIROBJ		= ./objs/

DIRLIB		= ./libft/

SRC			= ft_printf ft_printf_helper ft_printf_helper_2 ft_printf_util

SRCS		= $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

HEAD		= ./includes/ 

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

NAMELFT		= libft.a

CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} -I${DIRLIB} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd ${DIRLIB} && ${MAKE} && cp -v ${NAMELFT} ../${NAME}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

main:		$(NAME)
			${CC} -I ${DIRINC} -I ${DIRLIB} ${NAME} main.c

all:		$(NAME)

bonus: 		${NAME}

clean:
			${RM} ${OBJS}
			cd ${DIRLIB} && ${MAKE} clean

fclean:		clean
			${RM} $(NAME)
			cd ${DIRLIB} && ${MAKE} fclean

re:			fclean all

.PHONY:		all clean fclean re

