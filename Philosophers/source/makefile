# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slammari <slammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 16:04:35 by slammari          #+#    #+#              #
#    Updated: 2022/04/27 00:21:30 by slammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


OBJECTS = $(SRC:.c=.o)
NAME = philo

CC = cc 
CFLAGS = -Wall -Wextra -Werror

INC = philo.h

SRC = routine.c \
		init_data.c \
		dining.c \
		Philosophers.c \
		utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) $(INC) clean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)

re: fclean all