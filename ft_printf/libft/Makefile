# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 18:24:56 by ntesfu            #+#    #+#              #
#    Updated: 2022/02/04 16:02:11 by ntesfu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*-MakeFile -*-

NAME = libft.a
FILES = ft_isdigit.c ft_isalpha.c ft_isprint.c ft_strlen.c ft_isascii.c ft_isalnum.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_min.c ft_indexof.c ft_unsgn_numlen.c ft_strcapitalize.c
B_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS = ${FILES:.c=.o}
B_OBJS = ${B_FILES:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus: ${B_OBJS}
	ar rc ${NAME} ${B_OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}
	${RM} ${B_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean all
