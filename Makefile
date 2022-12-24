# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 15:25:33 by ael-maar          #+#    #+#              #
#    Updated: 2022/12/24 22:12:52 by ael-maar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIRS = ./src
INC_DIR = ./Includes
CFLAGS = -Wall -Wextra -Werror
# files for the mandatory server
SRCS_SERVER = $(SRCS_DIRS)/server.c $(SRCS_DIRS)/server_utils.c $(SRCS_DIRS)/signals.c $(SRCS_DIRS)/libft.c $(PRINTF_NAME)
# files for the mandatory client
SRCS_CLIENT = $(SRCS_DIRS)/client.c $(SRCS_DIRS)/signals.c $(SRCS_DIRS)/libft.c $(PRINTF_NAME)
# files for the bonus server
SRCS_BSERVER = $(SRCS_DIRS)/server_bonus.c $(SRCS_DIRS)/server_utils.c $(SRCS_DIRS)/signals.c $(SRCS_DIRS)/libft.c $(PRINTF_NAME)
# files for the bonus client
SRCS_BCLIENT = $(SRCS_DIRS)/client_bonus.c $(SRCS_DIRS)/client_utils.c $(SRCS_DIRS)/signals.c $(SRCS_DIRS)/libft.c $(PRINTF_NAME)
# names of the programs
NAME = server client

PRINTF_NAME = ./printf/libftprintf.a

all: $(NAME)

$(NAME): $(PRINTF_NAME) $(SRCS_SERVER) $(SRCS_CLIENT)
	gcc $(CFLAGS) $(SRCS_SERVER) -I $(INC_DIR) -I ./printf -o server
	gcc $(CFLAGS) $(SRCS_CLIENT) -I $(INC_DIR) -o client

$(PRINTF_NAME):
	make -C ./printf
	
bonus : $(PRINTF_NAME)
	gcc $(CFLAGS) $(SRCS_BSERVER) -I $(INC_DIR) -I ./printf -o server
	gcc $(CFLAGS) $(SRCS_BCLIENT) -I $(INC_DIR) -I ./printf -o client

clean:
	make clean -C ./printf

fclean: clean
	make fclean -C ./printf
	rm -rf $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus