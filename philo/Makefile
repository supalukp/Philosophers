# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 09:43:19 by spunyapr          #+#    #+#              #
#    Updated: 2025/03/18 20:36:51 by spunyapr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra 
INCLUDES = -I  

# Source files
SRC_DIR = sources
SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/parsing.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADER_PHILO = philo.h

NAME = philo

all: $(NAME)

$(NAME): Makefile $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -g3

%.o: %.c $(HEADER_PHILO) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus