# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slammari <slammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 16:04:35 by slammari          #+#    #+#              #
#    Updated: 2022/04/27 20:05:05 by slammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc 
CFLAGS = -Wall -Wextra -Werror

INC = bonus_philo.h

SRC = bonus_init.c \
		bonus_main.c \
		bonus_philo.c \
		bonus_time.c\
		bonus_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) $(INC) clean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)

re: fclean all