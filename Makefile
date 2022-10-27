# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntesfu <ntesfu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 18:24:56 by ntesfu            #+#    #+#              #
#    Updated: 2022/10/27 15:17:04 by ntesfu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*-MakeFile -*-

LIBFT_DIR = ft_printf/libft
LIBFT = libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = ft_printf.a

SOURCE = ./
INCLUDE = ./
CLIENT = client
SERVER = server

SRC_CLIENT	=	client.c
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)
SRC_SERVER	=	server.c
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} -I${FT_PRINTF_DIR} $< -o ${<:.c=.o}

all: $(FT_PRINTF) $(SERVER) $(CLIENT)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(SRC_SERVER) -L$(FT_PRINTF_DIR) -lftprintf -o $(SERVER)
	@echo $(BRIGHT_GREEN)"$(SERVER) has been created!"$(RESET)

$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(SRC_CLIENT) -L$(FT_PRINTF_DIR) -lftprintf -o $(CLIENT)
	@echo $(BRIGHT_GREEN)"$(CLIENT) has been created!"$(RESET)

clean:		
			cd $(FT_PRINTF_DIR) && ${MAKE} clean
			${RM} $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:		clean
			cd $(FT_PRINTF_DIR) && ${MAKE} fclean
			${RM} $(CLIENT) $(SERVER)

re:			fclean all

.PHONY:		all clean fclean re

