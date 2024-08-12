# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 15:41:51 by mahmoud           #+#    #+#              #
#    Updated: 2024/08/12 17:21:20 by mahmoud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	PhoneBook.cpp

NAME = PhoneBook
RM = rm -f
CC = c++
CPPFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)
	
%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re